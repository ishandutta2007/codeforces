#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pll pair<LL,LL>
#define pii pair<int,int>
#define LL long long
#define pb push_back
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-7
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        set<string> s;
        for(int i = 0;i<n;i++){
            char c[65];
            scanf("%s",c);
            s.insert(string(c));
        //    scanf("%s",c[i]);
        }
        LL need=((1ll<<m)-n-1)/2;
        string str;
        for(int i = 0;i<m;i++){
            LL cnt=(1ll<<(m-i-1));
            for(auto &it:s){
                if(it[i]=='0')cnt--;
            }
            //printf("%d\n",cnt);
            if(need>=cnt){
                need-=cnt,str+='1';
                vector<string> v;
                for(auto &it:s){
                    if(it[i]=='0')v.pb(it);
                }
                for(auto it:v)s.erase(it);
            }
            else{
                str+='0';
                vector<string> v;
                for(auto &it:s){
                    if(it[i]=='1')v.pb(it);
                }
                for(auto it:v)s.erase(it);
            }
        }
        cout<<str<<endl;
    }
}
/*
2 11 14
9 3
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
3**5+3**5-2**5
000111222
001112220
*/