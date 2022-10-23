#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int qq(vector<int> &v){
    printf("? %d",v.size());
    for(auto it:v){
        printf(" %d",it);
    }
    printf("\n");
    fflush(stdout);
    char c[50];
    scanf("%s",c);
    if(c[0]=='N')return 0;
    else return 1;
}
void query(vector<int> q){
    if(q.size()<=2){
        printf("! %d\n",q[0]);
        fflush(stdout);
        char c[50];
        scanf("%s",c);
        if(c[1]==')')return;
         printf("! %d\n",q[1]);
        fflush(stdout);
       // char c[50];
        scanf("%s",c);
        if(c[1]==')')return;
        assert(0);
    }
    vector<int> v[3];
    for(int i = 0;i<q.size();i++){
        v[i%3].pb(q[i]);
    }
    int x=qq(v[0]);
    if(x==1){
        int y=qq(v[1]);
        if(y==1){
             vector<int> vv;
            for(auto it:v[0])vv.pb(it);
            for(auto it:v[1])vv.pb(it);
            query(vv);
        }
        else{
              vector<int> vv;
            for(auto it:v[0])vv.pb(it);
            for(auto it:v[2])vv.pb(it);
            query(vv);
        }
    }
    else{
        x=qq(v[0]);
        if(x==1){
            int y=qq(v[1]);
            if(y==1){
                vector<int> vv;
                for(auto it:v[0])vv.pb(it);
                for(auto it:v[1])vv.pb(it);
                query(vv);
            }
            else{
                vector<int> vv;
                for(auto it:v[0])vv.pb(it);
                for(auto it:v[2])vv.pb(it);
                query(vv);
            }
        }
        else{
            vector<int> vv;
            for(auto it:v[1])vv.pb(it);
            for(auto it:v[2])vv.pb(it);
            query(vv);
        }
    }
}
void solve(int T){
    int n;
    scanf("%d",&n);
    vector<int> v;
    for(int i = 1;i<=n;i++)v.pb(i);
    query(v);
}

int main(){
    srand(time(NULL));
    int t=1;
   //  scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
1
2 4
3 
5
*/