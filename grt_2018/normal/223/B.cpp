#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back

const int MAXN = 200*1000+10;
int n,m;
string s,t;
int cnt[MAXN][27];
int rig[MAXN],lef[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s>>t;
    n=s.size();
    m=t.size();
    for(int i=0; i<m;i++) {
        cnt[i+1][t[i]-'a']++;
        for(int j=0; j<26;j++) {
            cnt[i+1][j]+=cnt[i][j];
        }
    }
    for(int i=0; i<n;i++) {
        rig[i+1]=rig[i];
        if(rig[i]+1<=m&&t[rig[i]]==s[i])
            rig[i+1]++;
    }
    for(int i=n-1; i>=0;i--) {
        lef[i+1] = lef[i+2];
        if(lef[i+2]+1<=m&&t[m-lef[i+2]-1]==s[i])
            lef[i+1]++;
    }
    for(int i=0; i<n;i++) {
        //cout<<rig[i+1]<<" "<<lef[i+1]<<"\n";
        if(cnt[rig[i+1]][s[i]-'a'] - cnt[m-lef[i+1]][s[i]-'a']<=0) {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}