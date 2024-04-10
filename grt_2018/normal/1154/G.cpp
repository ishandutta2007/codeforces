#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

const int MAXN = 1000*10000+1;
vi cnt[MAXN];
int n;
LL ans=(LL)1000*1000*1000*1000*1000*1000;
pi q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int a,i=0; i<n;i++) {
        cin>>a;
        cnt[a].PB(i);
    }
    for(int gc = 1; gc<MAXN; gc++) {
        vector<pi> p;
        for(int i=gc; i<MAXN; i+=gc) {
            if(cnt[i].size()==1) {
                p.PB({cnt[i][0],i});
            }
            else if(cnt[i].size()>=2) {
                int x=0;
                while(p.size()<2) {
                    p.PB({cnt[i][x],i});
                    x++;
                }
            }
            if(p.size()==2) break;
        }
        if(p.size()==2) {
            //cout<<p[0].ND<<" "<<p[1].ND<<" "<<gc<<"\n";
            //cout<<p[0].ST<<" "<<p[1].ST<<"\n";
            if(ans>(LL)p[0].ND*p[1].ND/gc) {
                ans=(LL)p[0].ND*p[1].ND/gc;
                q = {p[0].ST,p[1].ST};
            }
        }
    }
    q.ST++;
    q.ND++;
    if(q.ST<q.ND)
    cout<<q.ST<<" "<<q.ND;
    else cout<<q.ND<<" "<<q.ST;
}