#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> E[100005];
int head, tail, A[300], B[300];
int N, M, H, T, marked[100005];
bool ok;

void checkHydra(int x) {
    int heads = 0;
    for (int i = 0; i < int(E[x].size()); ++i)
        marked[E[x][i]] = 1, ++heads;

    if (heads >= H) {
        for (vector<int>::iterator it = E[x].begin(); it != E[x].end() && !ok; ++it) {
            // check tail
            --heads;
            int tails = 0;
            int common = 0;
            for (vector<int>::iterator jt = E[*it].begin(); jt != E[*it].end() && !ok; ++jt) {
                if (*jt == x)
                    continue;
                ++tails;
                if (marked[*jt])
                    ++common;
            
                if (heads >= H && tails >= T && heads + tails - common >= H + T) {
                    ok = true;
                    head = x;
                    tail = *it;
                }
            }
            ++heads;
        }
    }
    
    for (int i = 0; i < int(E[x].size()); ++i)
        marked[E[x][i]] = 0;
}

int main() {
    cin >> N >> M >> H >> T;

    for (int i = 0; i < M; ++i) {
        int x, y; cin >> x >> y;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    
    ok = false;
    for (int i = 1; i <= N && !ok; ++i)
        checkHydra(i);

    if (!ok) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    cout << head << " " << tail << "\n";
    for (auto &it: E[head])
        if (it != tail)
            marked[it]++;
    for (auto &it: E[tail])
        if (it != head)
            marked[it]++;

    N = M = 0;
    for (auto &it: E[head])
        if (marked[it] == 1)
            if (N < H) {
                A[N++] = it;
                marked[it] = 0;
            }

    for (auto &it: E[tail])
        if (marked[it] == 1)
            if (M < T) {
                B[M++] = it;
                marked[it] = 0;
            }

    for (auto &it: E[head])
        if (marked[it] == 2)
            if (N < H) {
                A[N++] = it;
                marked[it] = 0;
            }

    for (auto &it: E[tail])
        if (marked[it] == 2)
            if (M < T) {
                B[M++] = it;
                marked[it] = 0;
            }


    for (int i = 0; i < H; ++i)
        cout << A[i] << " ";
    cout << "\n";

    for (int i = 0; i < T; ++i)
        cout << B[i] << " ";
    cout << "\n";
}