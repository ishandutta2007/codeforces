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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 262144

int main(){
    //char s[]="abcabcabcabc";
    string s;
    int cnt[6];
    int val[105];
    MEM(cnt);
    s+="abcde";
    for(int i = 0;i<95;i++){
        s+=(char)(rand()%5+'a');
    }
    for(int i = 0;s[i]!=0;i++){
        if(s[i]=='a')cnt[0]++;
        else cnt[s[i]-'a']+=cnt[s[i]-'a'-1];
        val[i]=cnt[4];
        //printf("%d ",cnt[4]);
    }
    int n;
    scanf("%d",&n);
    int ans[105];
    MEM(ans);
    int tmp=n;
    for(int k = 99;k>=0;k--){
    //    sum+=tmp/val[k];
        ans[k]=tmp/val[k];
        tmp%=val[k];
        if(tmp==0)break;
    }
    string s2;
    for(int i =0;i<100;i++){
        printf("%c",s[i]);
        s2+=s[i];
        for(int j=0;j<ans[i];j++)printf("f"),s2+='f';
    }
    printf(" abcdef\n");
    MEM(cnt);
    for(int i = 0;s2[i]!=0;i++){
        if(s2[i]=='a')cnt[0]++;
        else cnt[s2[i]-'a']+=cnt[s2[i]-'a'-1];
    }
    assert(cnt[5]==n);
   // printf("%d %d\n",cnt[5],s2.size());
    /*
    for(int j=1;j<=1000000;j++){
        int sum=0;
        int tmp=j;
        for(int k=99;k>=0;k--){
            sum+=tmp/val[k];
            tmp%=val[k];
            if(tmp==0)break;
        }
        if(sum>=100){
            printf("%d\n",j);
        }
    }
    cout<<s<<endl;
    printf("\n");*/
}
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/