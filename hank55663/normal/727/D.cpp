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
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 30005
#define next Next
#define index Index
int main(){
    int a[6];
    for(int i = 0;i<6;i++)
        scanf("%d",&a[i]);
    string s[6]={"S","M","L","XL","XXL","XXXL"};
    //            1 2 3 4 5 6 7  8  9  10 11
    int n;
    scanf("%d",&n);
    vector<pii> v;
    for(int i = 0;i<n;i++){
        char c[15];
        scanf("%s",c);
        string Si(c);
        int num;
        for(int i = 0;i<6;i++){
            if(Si==s[i]){
                num=i*2;
            }
        }
        for(int i = 0;i<5;i++){
            if(Si==s[i]+","+s[i+1])
                num=i*2+1;
        }
        v.pb(mp(num,i));
    }
    sort(v.begin(),v.end());
    string ans[100005];
    for(auto it:v){
        if(it.x%2==0){
            if(a[it.x/2]==0){
                printf("NO\n");
                return 0;
            }
            ans[it.y]=s[it.x/2];
            a[it.x/2]--;
        }
        else{
            if(a[it.x/2]==0){
                if(a[it.x/2+1]==0){
                    printf("NO\n");
                    return 0;
                }
               // printf("%d %d\n",it.y,it.x/2+1);
                //cout<<s[it.x/2+1]<<endl;
                ans[it.y]=s[it.x/2+1];
                a[it.x/2+1]--;
            }
            else{
                ans[it.y]=s[it.x/2];
                a[it.x/2]--;
            }
        }
    }
    printf("YES\n");
    for(int i = 0;i<n;i++){
        printf("%s\n",ans[i].c_str());
    }
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */