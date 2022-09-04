#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>
#include<iostream>
#include<cmath>
#include<sstream>
#include<queue>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
//#define pii pair<int,int> 
#define N 1000005
int isprime[N];
vector<int> prime;
void Find(){
    fill(isprime,isprime+N,0);
    for(int i=2;i<N;i++){
        if(!isprime[i]){
            prime.pb(i);
            for(int j=i;j<N;j+=i){
                isprime[j]=i;
            }
        }
    }
}
pll gcd(LL a, LL b){
    if(b == 0) return mp(1, 0);
    else{
        LL p = a / b;
        pll q = gcd(b, a % b);
        return make_pair(q.y, q.x - q.y * p);
    }
}
int mod=1000;
LL f_pow(int a,int b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
bool check(int x){
    for(auto it:prime){
        if(it*it>x){
            break;
        }
        if(x%it==0){
            return false;
        }
    }
    return true;
}

char c[2005][2005];
int ok[2005][2005];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    scanf("%s",c[i]);
    queue<pii > q,q2;
    q.push(mp(0,0));
    MEMS(ok);
    ok[0][0]=k;
    string s;
    while(!q.empty()){
        int Maxa=0;
        int has=0;
        char add='z',small='z';
        while(!q.empty()){
            pii p=q.front();
           // printf("%d %d\n",p.x,p.y);
            q.pop();
            if(ok[p.x][p.y]){
                Maxa=1;
                int last=ok[p.x][p.y]-1;
                if(c[p.x][p.y]=='a'){
                    last++;
                }
                if(last)
                has=last;
                int x=p.x,y=p.y+1;
                if(y<n){
                    if(ok[x][y]==-1){
                        q2.push(mp(x,y));
                    }
                    ok[x][y]=max(ok[x][y],last);
                    small=min(small,c[x][y]);
                }
                x=p.x+1,y=p.y;
                if(x<n){
                    if(ok[x][y]==-1){
                        q2.push(mp(x,y));
                    }
                    ok[x][y]=max(ok[x][y],last);
                    small=min(small,c[x][y]);
                }
            }
            else{
                add=c[p.x][p.y];
               // printf("%d %d\n",p.x,p.y);
                int x=p.x,y=p.y+1;
                if(y<n){
                    if(ok[x][y]==-1){
                        q2.push(mp(x,y));
                        ok[x][y]=0;
                    }
                    
                    small=min(small,c[x][y]);
                }
                x=p.x+1,y=p.y;
                if(x<n){
                    if(ok[x][y]==-1){
                        q2.push(mp(x,y));
                        ok[x][y]=0;
                    }
                    
                    small=min(small,c[x][y]);
                }
            }
        }
       // printf("%d\n",add);
        if(Maxa){
            s+='a';
        }
        else{
            s+=add;
        }
        while(!q2.empty()){
            pii p =q2.front();q2.pop();
            if(has){
                if(ok[p.x][p.y])
                    q.push(p);
                else if(c[p.x][p.y]=='a')
                    q.push(p);
            }
            else if(c[p.x][p.y]==small)
                q.push(p);
        }
    }
    cout<<s<<endl;
}