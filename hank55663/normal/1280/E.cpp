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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
int Size[300005];
int f[300005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        LL r;
        scanf("%lld",&r);
        vector<pair<int,char> > v;
        char c[5000005];
        int index=0;
        scanf(" %c",&c[0]);
        int now=1;
        while(scanf("%c",&c[now])){
            c[now+1]=0;
            if(c[now]=='\n'){
                c[now]=0;
                break;
            }
            else{
                now++;
            }
        }
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='*'){
                Size[index]=1;
                f[index]=index;
                v.pb(mp(index++,0));
            }
            else if(c[i]==')'){
                int S=0,P=0;
                int tmp=-1;
                while(v.back().y!='('){
                    if(v.back().y==0){
                        if(S){
                            int a=Find(tmp),b=Find(v.back().x);
                            if(Size[a]>Size[b])tmp=v.back().x;
                        }
                        else{
                            if(tmp==-1){
                                tmp=v.back().x;
                            }
                            else{
                                int a=Find(tmp),b=Find(v.back().x);
                                f[b]=a;
                                Size[a]+=Size[b];
                            }
                        }
                    }
                    else{
                        if(v.back().y=='S')S=1;
                        else P=1;
                    }
                    v.pop_back();
                }
                v.pop_back();
                v.pb(mp(tmp,0));
            }
            else if(c[i]!=' '){
                v.pb(mp(0,c[i]));
            }
        }
        printf("REVOLTING");
        
        for(int i = 0;i<index;i++){
          //  printf("%d %d\n",Find(i),Size[Find(i)]);
            if(Find(i)==v.back().x)
            printf(" %lld",Size[v.back().x]*r);
            else
            printf(" 0");
        }
        printf("\n");
    }
}
/*
int main(){

"RGGGGRRRRG", "RG"
}*/