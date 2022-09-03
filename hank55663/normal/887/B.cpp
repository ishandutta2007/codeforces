#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
int main(){
    int n;
    scanf("%d",&n);
    vector<int> v;
    v.pb(0);
    int a[3][6];
    for(int i = 0;i<n;i++){
        for(int j  =0;j<6;j++)
            scanf("%d",&a[i][j]);
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<6;j++){
            v.pb(a[i][j]);
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i!=j){
                for(int k  =0;k<6;k++){
                    for(int k2=0;k2<6;k2++){
                        v.pb(a[i][k]*10+a[j][k2]);
                    }
                }
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j  =0;j<n;j++){
            for(int k=0;k<n;k++){
                if(i!=j&&j!=k&&i!=k){
                    for(int aa=0;aa<6;aa++){
                        for(int b=0;b<6;b++){
                            for(int c=0;c<6;c++)
                                v.pb(a[i][aa]*100+a[j][b]*10+a[k][c]);
                        }
                    }
                }
            }
        }
    }
    sort(v.begin(),v.end());
    unique(v.begin(),v.end());
    v.pb(1e9);
    for(int i = 0;i<v.size();i++){
        if(i!=v[i]){
            printf("%d\n",i-1);
            break;
        }
    }
} 
/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/