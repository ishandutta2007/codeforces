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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        string target;
        for(int i = 1 ; i < k;i++){
            target+="()";
        }
        for(int i=0;i<(n-k*2+2)/2;i++){
            target+="(";
        }
        for(int i=0;i<(n-k*2+2)/2;i++){
            target+=")";
        }
        char c[2005];
        scanf("%s",c);
        vector<pii> v;
        //cout<<target<<endl;
        for(int i = 0;c[i]!=0;i++){
            if(c[i]!=target[i]){
               // printf("%d %c %c\n",i,c[i],target[i]);
                for(int j=i+1;;j++){
                    if(c[j]==target[i]){
                        v.pb(mp(i+1,j+1));
                        reverse(c+i,c+j+1);
                      //  printf("%s\n",c);
                        break;
                    }
                }
            }
        }
        printf("%d\n",v.size());
        for(auto it:v){
            printf("%d %d\n",it.x,it.y);
        }
    }
}
/*
9 4 
1 0 1 0 1 0 0 1 1
1 2
2 4
2 3
4 5
1 6
6 7
6 8
7 9

*/