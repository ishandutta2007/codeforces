#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

const int MAXN= 200*1000+10;
int n,k;
int a[MAXN];
int o[MAXN];
int cl[MAXN],cr[MAXN];
int team[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0; i<n;i++) {
        cin>>a[i];
        o[a[i]] = i;
        cl[i]=i-1;
        cr[i]=i+1;
    }
    int q=1;
    for(int i=n;i>=1; i--) {
        if(team[o[i]]!=0) continue;
        team[o[i]] = q;
        int pos = o[i],tmp=-1,tmp2=n;
        for(int j=0; j<k;j++) {
            pos = cl[pos];
            if(pos==-1) break;
            team[pos] = q;
        }
        if(pos!=-1)
        tmp = cl[pos];
        pos=o[i];
        for(int j=0; j<k;j++) {
            pos=cr[pos];
            if(pos==n) break;
            team[pos] = q;
        }
        if(pos!=n) tmp2=cr[pos];
        if(tmp2!=-1) {
            cl[tmp2] = tmp;
        }
        cr[tmp] = tmp2;
        //cout<<tmp<<" "<<tmp2<<"\n";
        if(q==1) q=2;
        else q=1;
    }
    for(int i=0; i<n;i++) cout<<team[i];
}