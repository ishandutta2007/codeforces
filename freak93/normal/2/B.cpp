#include <iostream>
#include <vector>

using namespace std;

const int inf = 0x3f3f3f3f;

class Pair {
  public:
    int x, y;
    Pair(int _x = 0, int _y = 0): x(_x), y(_y) {}
    Pair operator+(const Pair &that) const {
        return Pair(x + that.x, y + that.y);
    }
    
    bool operator<(const Pair &that) const {
        if (x != that.x)
            return x < that.x;
        return y < that.y;
    }

    bool operator<<(const Pair &that) const {
        if (y != that.y)
            return y < that.y;
        return x < that.x;
    }
    
    bool operator!=(const Pair &that) const {
        return x != that.x || y != that.y;
    }
};

void rebuild(vector< vector<int> > &from, int x, int y) {
    if (x == 1 && y == 1)
        return;

    if (from[x][y] == 1) { 
        rebuild(from, x - 1, y);
        cout << "D";
    }
    else {
        rebuild(from, x, y - 1);
        cout << "R";
    }
}

const int erat = 1000005;

int main() {
    int N; cin >> N;

    vector< vector<Pair> > A(N + 1, vector<Pair>(N + 1, Pair(inf, inf))), best2 = A, best5 = A;
    vector< vector<int> > from2(N + 1, vector<int>(N + 1, 0)), from5 = from2;

    best2[0][1] = best5[0][1] = Pair(0, 0);

    vector<int> pow2(erat, 0), pow5(erat, 0);
    for (int i = 2, many = 1; i < erat; i *= 2, ++many)
        for (int j = i; j < erat; j += i)
            pow2[j] = many;
    for (int i = 5, many = 1; i < erat; i *= 5, ++many)
        for (int j = i; j < erat; j += i)
            pow5[j] = many;

    Pair have0(0, 0);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j) {
            int value; cin >> value;
            if (value == 0)
                have0 = Pair(i, j);

            A[i][j] = Pair(0, 0);

            while (value >= erat && value % 2 == 0) {
                value /= 2;
                ++A[i][j].x;
            }

            while (value >= erat && value % 5 == 0) {
                value /= 5;
                ++A[i][j].y;
            }
            if (value < erat)
                A[i][j] = A[i][j] + Pair(pow2[value], pow5[value]);

            if (best2[i - 1][j] < best2[i][j - 1]) {
                best2[i][j] = best2[i - 1][j] + A[i][j];
                from2[i][j] = 1;
            }
            else
                best2[i][j] = best2[i][j - 1] + A[i][j];

            if (best5[i - 1][j] << best5[i][j - 1]) {
                from5[i][j] = 1;
                best5[i][j] = best5[i - 1][j] + A[i][j];
            }
            else
                best5[i][j] = best5[i][j - 1] + A[i][j];
            //cerr << " ---> (" << best2[i][j].x << ", " << best2[i][j].y << ")   (" << best5[i][j].x << ", " << best5[i][j].y << ") <---\n";
        }

    if (have0 != Pair(0, 0) && min(best2[N][N].x, best5[N][N].y) > 1) {
        cout << "1\n";
        for (int i = 1; i < have0.x; ++i)
            cout << "D";
        for (int j = 1; j < have0.y; ++j)
            cout << "R";

        for (int i = have0.x; i < N; ++i)
            cout << "D";
        for (int j = have0.y; j < N; ++j)
            cout << "R";
        return 0;
    }
    cout << min(best2[N][N].x, best5[N][N].y) << "\n";
    if (best2[N][N].x < best5[N][N].y)
        rebuild(from2, N, N);
    else
        rebuild(from5, N, N);
}