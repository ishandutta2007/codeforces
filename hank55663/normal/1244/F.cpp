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
#define MXN 300000
int solve(){
    int n=100,k=rand()%2+1;
    scanf("%d %d",&n,&k);
    //srand(time(NULL));
    char c[400005];
    MEM(c);
    scanf("%s",c);
    //printf("%d %d\n",n,k);
   /* for(int i =0;i<n;i++){
        if(rand()&1)c[i]='B';
        else c[i]='W';
    }
    printf("%s\n",c);
    //scanf("%s",c);
    char c2[400005];
    for(int i = 0;i<n;i++)
        c2[i]=c[i];
    for(int i = 0;i<k;i++){
        char c3[400005];
        for(int j=0;j<n;j++){
            int l=(j+n-1)%n,r=(j+1)%n;
            int b=0,w=0;
            if(c2[l]=='B')b++;else w++;
            if(c2[j]=='B')b++;else w++;
            if(c2[r]=='B')b++;else w++;
           // printf("%d %c %c %c %d %d\n",c2[l],c2[i],c2[r],b,w);
            if(b>w)c3[j]='B';
            else c3[j]='W';
        }
        for(int j=0;j<n;j++){
            c2[j]=c3[j];
        }
    }
    printf("%s\n",c2);*/
    for(int i =n;i<2*n;i++){
        c[i]=c[i-n];
    }
    c[2*n]=c[0];
  //  printf("%s\n",c);
    for(int i =0;i<2*n-1;i++){
        if(c[i]==c[i+1]){
            vector<pii> v;
            int st=i+2;
            while(c[st]==c[st-1])st++;
            for(int j=st-i;j<=n;j++){
                //printf("%d %d\n",i,i+j);
                if(c[i+j]==c[i+j+1]){
                    v.pb(mp(st,i+j-1));
                    //printf("%d %d %d %d\n",i,j,st,i+j-1);
                    while(c[i+j]==c[i+j+1]&&j<=n)
                    j++;
                    j--;
                    st=i+j+2;
                  //  printf("%d\n",j);
                }
            }       
            for(auto it:v){
                int l=it.x-1,r=it.y+1;
                for(int i=0;i<k;i++){
                    if(it.x>it.y)break;
                    c[it.x]=c[l];
                    c[it.y]=c[r];
                    it.x++;
                    it.y--;
                }
                if((k&1)&&it.x<=it.y){
                    for(int j=it.x;j<=it.y;j++){
                        if(c[j]=='B')c[j]='W';
                        else c[j]='B';
                    }
                }
            }
            for(int j=0;j<n;j++){
                if(i+j>=n){
                    c[i+j-n]=c[i+j];
                }
            }
            c[n]=0;
            printf("%s\n",c);
           // for(int j = 0;j<n;j++){
              //  assert(c[j]==c2[j]);
          //  }
            return 0;
        }
    }
    if(k&1){
        c[n]=0;
        printf("%s",c+1);
        printf("%c\n",c[0]);
    }
    else{
        c[n]=0;
        printf("%s\n",c);
    }
}
int main(){
    for(int t=0;t<1;t++){
        solve();
    }
}
/*
5 4
8 1 0 3 0
0 0 1 3 8
1
*/