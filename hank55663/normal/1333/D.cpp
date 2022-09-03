#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    char c[3005];
    scanf("%s",c+1);
    int tot=0;
    int cnt=0;
    for(int i = n;i>=1;i--){
        if(c[i]=='R'){
            tot+=n-i-cnt;
            cnt++;
        }
    }
    if(tot<k){
        printf("-1\n");
    }
    else{
        vector<vector<int>> v;
        while(true){
            vector<int> tmp;
            for(int i = 1;i<=n;i++){
                if(c[i]=='R'&&c[i+1]=='L'){
                    tmp.pb(i);
                    swap(c[i],c[i+1]);
                    i++;
                }
            }
            if(tmp.empty())break;
            v.pb(tmp);
        }
        if(v.size()>k){
            printf("-1\n");
        }
        else{
            for(int i = 0;i<v.size();i++){
                reverse(v[i].begin(),v[i].end());
                while(k!=v.size()-i&&v[i].size()){
                    printf("1 %d\n",v[i].back());
                    v[i].pop_back();
                    k--;
                }
                if(v[i].empty())continue;
                else{
                    printf("%d",v[i].size());
                    for(auto it:v[i]){
                        printf(" %d",it);
                    }
                    printf("\n");
                    k--;
                }
            }
        }
    }
}
/*

*/