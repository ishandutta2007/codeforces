#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int val1[2000005],val2[2000005];
int cnt[1000005][2];
int inrow[1000005][2];
void solve(){
    int n;
    scanf("%d",&n);
    char c[1000005];
    scanf("%s",c+1);
    fill(val1,val1+2000005,1e9);
    fill(val2,val2+2000005,1e9);
    for(int i = 1;c[i]!=0;i++){
        cnt[i][0]=cnt[i-1][0];
        cnt[i][1]=cnt[i-1][1];
        inrow[i][0]=inrow[i-1][0];
        inrow[i][1]=inrow[i-1][1];
        if(c[i]=='0'){
            cnt[i][0]++;
            inrow[i][0]++;
            inrow[i][1]=0;
        }
        else if(c[i]=='1'){
            cnt[i][1]++;
            inrow[i][1]++;
            inrow[i][0]=0;
        }
        else{
            cnt[i][0]++;
            cnt[i][1]++;
            inrow[i][0]++;
            inrow[i][1]++;
        }
        val1[cnt[i][0]]=min(val1[cnt[i][0]],i);
        val2[cnt[i][1]]=min(val2[cnt[i][1]],i);
    }
    for(int x = 1;x<=n;x++){
        int ans=0;
        int now=0;
        while(now!=n){
            if(now+x>n)break;
            if(cnt[now+x][0]-cnt[now][0]==x||cnt[now+x][1]-cnt[now][1]==x){
                ans++;
                now=now+x;
            }
            else{
                 //printf("%d %d\n",inrow[now+x][0],inrow[now+x][1]);
                now=now+x-max(inrow[now+x][0],inrow[now+x][1]);
               
            }
            //printf("%d\n",now);
        }
        printf("%d ",ans);
    }
    printf("\n");
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/