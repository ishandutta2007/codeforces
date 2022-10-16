#include <stdio.h>
#include <set>
#include <map>
#include <string.h>

using namespace std;

int prev[200000];
int op;

map< pair<int, int>, set<int> > queries[8000];
int input[8000][10];
int ans[8000];

int n,m;
int t,l,r,v;

int main() {
    memset(ans,-1,sizeof(ans));

    int cur = 1;
    for (int i = 1; i < 120000; i++) {
        prev[cur++] = i;
        if ((i & (i-1)) == 0) {
            prev[cur++] = i;
        }
    }

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d %d %d", &t, &l, &r, &v);
            input[i][0]=op;
            input[i][1]=t;
            input[i][2]=l;
            input[i][3]=r;
            input[i][4]=v;
        }
        else {
            scanf("%d %d", &t, &v);
            input[i][0]=op;
            input[i][1]=t;
            input[i][2]=v;
            queries[t][make_pair(i,v)] = set<int>();
        }
    }

    for (int i = m-1; i >= 0; i--) {
        if (input[i][0] == 1) {
            int t = input[i][1];
            int l = input[i][2];
            int r = input[i][3];
            int v = input[i][4];

            while (t >= 1) {
                //printf("%d %d %d\n", t, l, r);
                for (map< pair<int, int>, set<int> >::iterator it = queries[t].begin(); it != queries[t].end(); it++) {
                    if (it->first.second >= l && it->first.second <= r && it->first.first > i) {
                        //printf("insere operacao %d na query %d\n", i, it->first.first);
                        queries[t][it->first].insert(v);
                    }
                }

                l = prev[l];
                r = prev[r];
                t--;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (input[i][0] == 2) 
            printf("%d\n", queries[input[i][1]][make_pair(i, input[i][2])].size());
    }
}