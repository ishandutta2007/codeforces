#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int normalize(vector< pair<int, int> > &H, int N) {
    sort(H.begin(), H.end());
    int tocut = 0;
    int lastcut = 0;
    for (auto &segment: H) {
        //cerr << "segment: " << segment.first << " " << segment.second << "\n";
        if (segment.first > lastcut)
            lastcut = segment.first;
        if (segment.second > lastcut) {
            tocut += segment.second - lastcut;
            lastcut = segment.second;
        }
    }

    return N - tocut;
}

int solve(map<int , vector<pair<int, int> > > &H, int N, int M) {
    int answer = 0;
    for (map<int ,vector<pair<int, int> > >::iterator it = H.begin(); it != H.end(); ++it) {
        int realsize = normalize(it -> second, N);
        //cerr << it -> first << " -> " << realsize << "\n";
        answer ^= realsize;
    }
    
    if ((M - 1 - H.size()) % 2)
        answer ^= N;
    return answer;
}

pair<int, int> remove(int left, vector< pair<int ,int> > &H, int N) {
    sort(H.begin(), H.end());
    int lastcut = 0;

    int toerase = N - left;

    for (auto &segment: H) {
        //cerr << "current: " << toerase << "\n";
        //cerr << segment.first << " " << segment.second << "\n";
        if (segment.first > lastcut)
            lastcut = segment.first;
        if (segment.second > lastcut) {
            if (lastcut < toerase)
                toerase += segment.second - lastcut;
            lastcut = segment.second;
        }
    }

    return {0, toerase};
}

bool find(map<int, vector<pair<int, int> > > &H, int N, int M, int V, bool reverse = false) {
    for (map<int, vector<pair< int, int> > >::iterator it = H.begin(); it != H.end(); ++it) {
        int realsize = normalize(it -> second, N);
        if ((realsize xor V) <= realsize) {
            auto segment = remove(realsize xor V, it -> second, realsize);
            if (reverse)
                cout << it -> first << " " << segment.first << " " << it -> first << " " << segment.second << "\n";
            else
                cout << segment.first << " " << it -> first << " " << segment.second << " " << it -> first << "\n";
            return true;
        }
    }

    for (int i = 1; i < M; ++i)
        if (H.find(i) == H.end()) {
            if ((N xor V) <= N) {
                if (reverse)
                    cout << i << " " << 0 << " " << i << " " << N - (N xor V) << "\n";
                else
                    cout << 0 << " " << i << " " << N - (N xor V) << " " << i << "\n";
                return true;
            } else {
                break;
            }
        }
    return false;
}

int main() {
    int N, M, K; cin >> N >> M >> K;

    map<int, vector< pair<int, int> > > H, V;
    for (int i = 0; i < K; ++i) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            if (y1 > y2)
                swap(y1, y2);
            V[x1].push_back({y1,y2});
        }

        if (y1 == y2) {
            if (x1 > x2)
                swap(x1, x2);
                H[y1].push_back({x1, x2});
        }
    }

    int answer = solve(H, N, M);
    answer ^= solve(V, M, N);
    if (answer == 0) {
        cout << "SECOND\n";
    } else {
        cout << "FIRST\n";
        if (find(H, N, M, answer))
            return 0;
        find(V, M, N, answer, true);
    }
}