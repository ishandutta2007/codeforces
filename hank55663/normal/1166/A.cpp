#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
int main(){
    int n;
    scanf("%d",&n);
    int cnt[105];
    fill(cnt,cnt+105 ,0);
    for(int i=0;i<n;i++){
        char c[105];
        scanf("%s",c);
        cnt[c[0]-'a']++;
    }
    int ans=0;
    for(int i =0;i<26;i++)
    {
        int x=cnt[i]/2;
        int y=cnt[i]-x;
        ans+=x*(x-1)/2+y*(y-1)/2;
    }
    printf("%d\n",ans);
}