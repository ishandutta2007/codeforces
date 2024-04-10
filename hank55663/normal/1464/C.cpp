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
using namespace std;
#define N 1000000
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
string str;
set<string> dc(int l,int r){
    if(l==r){return set<string>{"0"};}
    set<string> res;
    for(int i = l ;i<r;i++){
        set<string> s1=dc(l,i),s2=dc(i+1,r);
        set<string> s3;
        for(auto it:s1){
            for(auto &it2:it){
                if(it2=='0')it2='1';
                else it2='0';
            }
            s3.insert(it);
        }
        swap(s1,s3);
        for(auto it:s1){
            for(auto it2:s2){
                res.insert(it+it2);
            }
        }
    }
    return res;
}
bool solve(){
    LL n,t;
    scanf("%lld %lld",&n,&t);
   // for(int i = 0;i<n;i++){
    //    s+='0';
    //}
  //  set<string> ss=dc(1,n);
//    for(auto it:ss)cout<<it<<endl;
    char c[100005];
    scanf("%s",c);
    t-=1ll<<(c[n-1]-'a');
    t+=1ll<<(c[n-2]-'a');
    LL sum=0;
    for(int i = 0;i<n-2;i++){
        sum+=1ll<<(c[i]-'a');
    }
  //  printf("%d %d\n",sum,t);
    {
        LL cnt[26];
        fill(cnt,cnt+26,0);
        for(int i = 0;i<n-2;i++){
            cnt[c[i]-'a']++;
        }
        for(int i = 25;i>=0;i--){
            while(sum-(1ll<<(i+1))>=t&&cnt[i]){
                cnt[i]--;
                sum-=(1ll<<(i+1));
            }
        }
        if(sum==t)printf("Yes\n");
        else printf("No\n");
    }
    return true;
}
int main(){
    int t=1;//000000;//000000;
    //scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/