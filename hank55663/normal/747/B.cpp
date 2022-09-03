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
#define MXN 10005
#define less Less
int main(){
    int n;
    scanf("%d",&n);
    map<char,int> m;
    if(n%4!=0){
        printf("===\n");
        return 0;
    }
    m['A']=n/4;
    m['G']=n/4;
    m['C']=n/4;
    m['T']=n/4;
    char c[300];
    scanf("%s",c);
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='?');
        else{
            m[c[i]]--;
        }
    }

    for(auto it:m){
        if(it.y<0){
            printf("===\n");
            return 0;
        }
    }
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='?'){ 
            while(m.begin()->y==0){
                m.erase(m.begin());
            }
            c[i]=m.begin()->x;
            m.begin()->y--;
           
        }
    }
    printf("%s\n",c);
}