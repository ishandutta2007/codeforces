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
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 100005
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char c[205];
        set<int> v[26];
        scanf("%s",c);
        if(strlen(c)==1){
            printf("YES\nabcdefghijklmnopqrstuvwxyz\n");
            continue;
        }
        for(int i = 1;c[i]!=0;i++){
            v[c[i]-'a'].insert(c[i-1]-'a');
            v[c[i-1]-'a'].insert(c[i]-'a');
        }
        vector<int> zero,one;
        int ok=1;
        for(int i = 0;i<26;i++){
            if(v[i].size()>2)ok=0;
            else if(v[i].size()==1)one.pb(i);
            else if(v[i].empty())zero.pb(i);
        }
        if(!ok||one.empty()){
            printf("NO\n");
        }
        else{
            printf("YES\n");
            for(auto it:zero)printf("%c",it+'a');
            printf("%c",one[0]+'a');
            int now=*v[one[0]].begin();
            int last=one[0];
            while(v[now].size()==2){
                printf("%c",now+'a');
                int tmp=now;
                for(auto it:v[tmp]){
                    if(it!=last)now=it;
                }
                last=tmp;
            }
            printf("%c\n",now+'a');
        }
    }
}