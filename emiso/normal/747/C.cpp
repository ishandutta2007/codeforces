#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

struct event {
    int time, tipo, servers;
    event (int time, int tipo, int s) : time(time), tipo(tipo), servers(s) {}

    bool operator <(const event &other) const {
        if(time == other.time)
            return tipo > other.tipo;
        return time < other.time;
    }
};

int active[110], liv, t[100100], k[100100], d[100100];
vector<int> tasks[100100];

int main() {
    int n, q;
    priority_queue <event> pfila;
    scanf("%d %d",&n, &q);

    for(int i=1; i<=q; i++) {
        scanf("%d %d %d",&t[i], &k[i], &d[i]);
        pfila.push(event(-t[i], i, k[i]));
        pfila.push(event(- t[i] - d[i], -i, k[i]));
    }

    liv = n;
    while(!pfila.empty()) {
        event a = pfila.top();
        pfila.pop();

        if(a.tipo > 0) {
            //printf("%d %d\n", liv, a.servers);
            if(liv < a.servers) {
                printf("-1\n");
                continue;
            }

            long long ans = 0;
            int rem = a.servers;
            for(int i=1;(i<=n && rem > 0);i++) {
                if(!active[i]) {
                    liv--;
                    active[i] = 1;
                    tasks[a.tipo].push_back(i);
                    ans += i;
                    rem--;
                }
            }
            printf("%lld\n",ans);
        }
        else {
            for(int i=0;i<tasks[-a.tipo].size();i++) {
                int z = tasks[-a.tipo][i];
                active[z] = 0;
                liv++;
            }
        }
    }
    return 0;
}