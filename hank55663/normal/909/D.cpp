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
#define MEM(x) memset(x,0,sizeof(x))
int mod=1e9+7;
int main(){
    vector<pair<char,int> > v;
    char c[1000005];
    scanf("%s",c);
    char temp=c[0];
    int cnt=0;
    for(int i=0;c[i]!=0;i++){
        if(c[i]==temp){
            cnt++;
        }
        else{
            v.pb(mp(temp,cnt));
            temp=c[i];
            cnt=1;
        }
    }
    v.pb(mp(temp,cnt));
    for(int i = 0;;i++){
       
        if(v.size()<=1){
            printf("%d\n",i);
            break;
        }
        for(int j=0;j<v.size();j++){
            if(j==0||j==v.size()-1){
                v[j].y--;
            }
            else{
                v[j].y-=2;
            }
        }
        vector<pair<char,int> > tt;
        for(auto it:v){
            if(it.y>0){
                if(tt.empty()||tt.back().x!=it.x){
                    tt.pb(it);
                }
                else{
                    auto p=tt.back();
                    tt.pop_back();
                    p.y+=it.y;
                    tt.pb(p);
                }
            }
        }
        swap(tt,v);
    }
}