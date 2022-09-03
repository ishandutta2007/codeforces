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
int main(){
   int cnt[10];
   char a[20],b[20];
   scanf("%s %s",a,b);
   int lena=strlen(a),lenb=strlen(b);
   if(lena<lenb){
       sort(a,a+lena);
       reverse(a,a+lena);
       printf("%s\n",a);
   }
   else{
       fill(cnt,cnt+10,0);
       for(int i = 0;a[i]!=0;i++){
           cnt[a[i]-'0']++;
       }
       int ok=0;
       vector<int> v;
       for(int i = 0;b[i]!=0;i++){
           if(ok){
               for(int j = 9;j>=0;j--){
                   if(cnt[j]){
                    //printf("%d",j);
                    v.pb(j);
                    cnt[j]--;
                    break;
                   }
               }
           }
           else if(cnt[b[i]-'0']){
               cnt[b[i]-'0']--;
               //printf("%c",b[i]);
               v.pb(b[i]-'0');
           }
           else{
               for(int j = b[i]-'0';j>=0;j--){
                   if(cnt[j]){
                       cnt[j]--;
                       v.pb(j);
                       ok=1;
                       //printf("%d",j);
                       break;
                   }
               }
               if(!ok){
                   while(true){
                       int x=v.back();
                       v.pop_back();
                       cnt[x]++;
                       for(int i = x-1;i>=0;i--){
                           if(cnt[i]){
                               v.pb(i);
                               cnt[i]--;
                               goto next;
                           }
                       }
                   }
                   next:
                   for(int i = 9;i>=0;i--){
                       while(cnt[i]){
                           v.pb(i);
                           cnt[i]--;
                       }
                   }
                   break;
               }
           }
       }
       for(auto it:v)
       printf("%d",it);
       printf("\n");
   }
}
/*

262143999937856
*/