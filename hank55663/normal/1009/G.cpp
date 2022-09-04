#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int tot[26];
int match[8][65];
int vis[105];
int dfs(int a){
    for(int i=0;i<6;i++){
        if((1<<i)&a){
        //    printf("%d %d\n",i,a);
            if(tot[i]){
                tot[i]--;
                match[i][a]++;
          //      printf("%d\n",i);
                return i;
            }
            else{
                for(int j=0;j<65;j++){
                    if(match[i][j]&&!vis[j]){
                        vis[j]=1;
                        if(dfs(j)!=-1){
                            match[i][j]--;
                            match[i][a]++;
                            return i;
                        }
                    }
                }
            }
        }
    }
    return -1;
}
int main(){
    char c[100005];
    scanf("%s",c);
    for(int i=0;c[i]!=0;i++){
        tot[c[i]-'a']++;
    }
    int len=strlen(c);
    int num[100005];
    fill(num,num+len,63);
    int m;
    scanf("%d",&m);
    while(m--){
        int pos;
        char cc[10];
        scanf("%d %s",&pos,cc);
        int sum=0;
        for(int i=0;cc[i]!=0;i++){
            sum|=(1<<(cc[i]-'a'));
        }
        num[pos-1]=sum;
    }
    for(int i=0;i<len;i++){
        MEM(vis);
        int x=dfs(num[i]);
       // printf("%d\n",x);
        if(x==-1){
            printf("Impossible\n");
            return 0;
        }
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<8;j++){
            if(match[j][num[i]]){
                match[j][num[i]]--;
                tot[j]++;
                break;
            }
        }
        MEM(vis);
        int x=dfs(num[i]);
        //printf("%d\n",x);
        //printf("%d %d\n",num[i],x);
        printf("%c",x+'a');
        match[x][num[i]]--;
    }
	return 0;
}