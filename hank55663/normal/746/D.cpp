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
#define less Less
int main(){
    int n,k,a,b;
    scanf("%d %d %d %d",&n,&k,&a,&b);
    if(a+b<n){
        printf("NO\n");
        return 0;
    }
    string ans;
    int cnt=0;
    while(ans.size()!=n){
        if(a>b){
            cnt++;
            if(cnt>k&&ans.back()=='G'){
                b--;
                ans+='B';
                cnt=1;
            }
            else{
                a--;
                if(ans.back()=='B')
                cnt=1;
                ans+='G';
              //  cnt++;
            }
        }
        else{
            cnt++;
            if(cnt>k&&ans.back()=='B'){
                a--;
                ans+='G';
                cnt=1;
            }
            else{
                b--;
                if(ans.back()=='G')
                    cnt=1;
                ans+='B';
             //   cnt++;
            }
        }
        //printf("%d\n",cnt);
    }
    if(a<0||b<0){
        printf("NO\n");
        return 0;
    }
    cout<<ans<<endl;
}
/*
4
8
2 2 4
3 1 3 5
1 2
2 1 5
4 2 6 4 7
2 5 8
2 8 5
2 7 6
 */