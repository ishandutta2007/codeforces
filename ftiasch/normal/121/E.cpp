#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int N = 111111;
const int C = 555;
const int M = 11111;

int n, m, size, num[N], delta[C], numCnt[C][M];
queue <int> myQueue;
vector <int> lucky;

int main () {
    myQueue.push(4);
    myQueue.push(7);
    while (!myQueue.empty()) {
        long long cur = myQueue.front();
        myQueue.pop();
        lucky.push_back(cur);
        if (cur * 10 + 4 <= 10000) {
            myQueue.push(cur * 10 + 4);
        }
        if (cur * 10 + 7 <= 10000) {
            myQueue.push(cur * 10 + 7);
        }
    }
    sort(lucky.begin(), lucky.end());
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", num + i);
    }
    memset(delta, 0, sizeof(delta));
    memset(numCnt, 0, sizeof(numCnt));
    size = (int)ceil(sqrt((double)n));
    for (int i = 0; i < n; ++ i) {
        numCnt[i / size][num[i]] ++;
    }
    while (m --) {
        int a, b, d;
        char buffer[22];
        scanf("%s%d%d", buffer, &a, &b);
        a --;
        b --;
        if (strcmp(buffer, "count") == 0) {
            int result = 0,
                aa = a / size,
                bb = b / size;            
            for (int i = min((aa + 1) * size - 1, b); i >= a; -- i) {                
                for (vector <int> :: iterator iter = lucky.begin();
                        iter != lucky.end(); ++ iter) {       
                    result += num[i] + delta[aa] == *iter;
                }
            }
            for (int i = aa + 1; i <= bb - 1; ++ i) {
                for (vector <int> :: iterator iter = lucky.begin();
                        iter != lucky.end(); ++ iter) {       
                    result += numCnt[i][*iter - delta[i]];
                }
            }
            if (aa != bb) {
                for (int i = bb * size; i <= b; ++ i) {
                    for (vector <int> :: iterator iter = lucky.begin();
                            iter != lucky.end(); ++ iter) {       
                        result += num[i] + delta[bb] == *iter;
                    }
                }
            }
            printf("%d\n", result);
        } else {
            scanf("%d", &d);
            int aa = a / size,
                bb = b / size;
            for (int i = min((aa + 1) * size - 1, b); i >= a; -- i) {
                numCnt[aa][num[i]] --;
                num[i] += d;
                numCnt[aa][num[i]] ++;
            }
            for (int i = aa + 1; i <= bb - 1; ++ i) {
                delta[i] += d;
            }
            if (aa != bb) {
                for (int i = bb * size; i <= b; ++ i) {
                    numCnt[bb][num[i]] --;
                    num[i] += d;
                    numCnt[bb][num[i]] ++;
                }
            }
        }
    }
    return 0;
}