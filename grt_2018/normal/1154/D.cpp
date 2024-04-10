#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

int a,b,n;
bool s[200*1000+1];
int act_a, act_b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>b>>a;
    for(int i=0; i<n;i++) cin>>s[i];
    act_a = a;
    act_b = b;
    int ind = 0;
    while((act_a>=0||act_b>=0)&&ind<n) {
        if(!s[ind]) {
            if(act_a>0) act_a--;
            else act_b--;
        }
        else {
            if(act_b>0&&act_a!=a) {
                act_b--;
                act_a=min(act_a+1,a);
            }
            else {
                act_a--;
            }
        }
        //cout<<act_a<<" "<<act_b<<"\n";
        ind++;
        if(act_a==0&&act_b==0) break;
    }
    cout<<ind;
}