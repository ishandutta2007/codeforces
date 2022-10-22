#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

const int MAXN = 100*1000+10;
int n;
LL ans=(LL)2000*1000*1000*1000*1000;
int a[MAXN];
int ent;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
        cin>>a[i];
        int x = (a[i]-i-1)/n+1;
        if(a[i]-i-1<0) x=0;
        if((LL)n*x+i<ans) {
            ans = (LL)n*x+i;
            ent = i+1;
        }
    }
    cout<<ent;
}