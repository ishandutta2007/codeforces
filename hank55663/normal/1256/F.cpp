#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 1500

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int> v[26];
        vector<int> vv[26];
        char c[200005];
        scanf("%s",c);
        for(int i = 0;i<n;i++){
            v[c[i]-'a'].pb(i);
            vv[c[i]-'a'].pb(i);
        }
        int ook=0;
        for(int i = 0;i<26;i++){
            if(v[i].size()>1)ook=1;
        }
        int tot=0;
        scanf("%s",c);
        int ok=1;
        for(int i=0;i<n;i++){
            if(v[c[i]-'a'].empty()){
                ok=0;
                break;
            }
            tot+=v[c[i]-'a'].back()-i;
            v[c[i]-'a'].pop_back();
        }
        if(!ok)printf("NO\n");
        else if(ook)printf("YES\n");
        else{
            int a[26];
            for(int i=0;c[i]!=0;i++)
            a[i]=vv[c[i]-'a'][0];
            int tot=0;
            for(int i= 0;c[i]!=0;i++)
                for(int j=i+1;c[j]!=0;j++){
                    if(a[j]<a[i])tot++;
                }
            if(tot&1)printf("NO\n");
            else printf("YES\n");
        }
    }
}