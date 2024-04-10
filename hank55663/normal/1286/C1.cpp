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
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
vector<multiset<char> > cal(vector<string> v,int n){
    vector<multiset<char> > res(n);
    vector<vector<string> > tmp(n+1);
    for(auto it:v){
        tmp[it.size()].pb(it);
    }
    int cnt[26];
    MEM(cnt);
    for(auto it:tmp[n][0])
        cnt[it-'a']++;
    vector<int> vv;
    int lastneed[26];
    MEM(lastneed);
    for(int i =n-1;i>=1;i--){
     //   printf("! %d\n",i);
        if(n-1-i>i)break;
        int need[26];
        for(int j=0;j<26;j++)
            need[j]=cnt[j]*tmp[i].size();
        /*for(int i = 0;i<3;i++)
            printf("%d ",need[i]);
        printf("\n");*/
        for(auto it:tmp[i]){
            for(auto it2:it){
                need[it2-'a']--;
                //printf("%c",it2);
            }
        }
       /* for(int i = 0;i<3;i++)
            printf("%d ",need[i]);
        printf("\n");*/
        for(int j=0;j<26;j++)
            need[j]-=lastneed[j];
       /* printf("%d\n",i);
        for(int i = 0;i<3;i++)
            printf("%d ",need[i]);
        printf("\n");*/
        for(auto it:vv)
            need[it]--;
        /*for(int i = 0;i<3;i++)
            printf("%d ",need[i]);
        printf("\n");*/
        if(n-1-i==i)
        for(int j=0;j<26;j++){
            if(need[j])
                res[i].insert(j+'a');
        }
        else
        for(int j=0;j<26;j++){
            for(int k=0;k<need[j];k++){
                res[n-1-i].insert(j+'a');
                res[i].insert(j+'a');
                vv.pb(j);
               // printf("%d ",j);
            }
        }
        //printf("\n");
        for(auto it:vv)
            need[it]++;
        need[vv.back()]--;
        need[vv[vv.size()-2]]--;
        for(int j=0;j<26;j++)
            lastneed[j]+=need[j];
    }
    return res;
}
/*
0 0 1 1 1
1 0 0 1 1
1 1 0 0 1
1 1 1 0 0*/
int main(){
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("? 1 1\n");
        fflush(stdout);
        char c[105];
        scanf("%s",c);
        printf("! %s\n",c);
        fflush(stdout);
        return 0;
    }
    else if(n==2){
        printf("? 1 1\n");
        fflush(stdout);
        char c1,c2;
        scanf(" %c",&c1);
        printf("? 2 2\n");
        fflush(stdout);
        scanf(" %c",&c2);
        printf("! %c%c\n",c1,c2);
        fflush(stdout);
        return 0;
    }
    else{
        printf("? 1 %d\n",n);
        fflush(stdout);
        vector<string> v;
        string tmp1;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                char c[105];
                scanf("%s",c);
                if(strlen(c)>tmp1.size())
                tmp1=string(c);
                v.pb(string(c));
            }
        }
       // printf("?\n");
        vector<multiset<char> > res1=cal(v,n);
        /*for(auto it:res1){
            for(auto it2:it)
            printf("%c ",it2);
            printf("\n");
        }*/
        v.clear();
        printf("? 1 %d\n",n-1);
        fflush(stdout);
       // vector<string> v;
        string tmp2;
        for(int i = 1;i<=n-1;i++){
            for(int j=i;j<=n-1;j++){
                char c[105];
                scanf("%s",c);
                if(strlen(c)>tmp2.size())
                tmp2=string(c);
                v.pb(string(c));
            }
        }
        vector<multiset<char> > res2=cal(v,n-1);
        /*for(auto it:res2){
            for(auto it2:it)
            printf("%c ",it2);
            printf("\n");
        }*/
        char ans[105];
        MEM(ans);
        int cnt[26];
        MEM(cnt);
        for(auto it:tmp1){
            cnt[it-'a']++;
        }
        for(auto it:tmp2){
            cnt[it-'a']--;
        }
        for(int i = 0;i<26;i++){
            if(cnt[i])ans[n-1]=i+'a';
        }
     //   printf("%d %c\n",n-1,ans[n-1]);
        int l=0,r=n-2;
        while(l<=r){
            res1[l].erase(res1[l].find(ans[r+1]));
            ans[l]=*res1[l].begin();
       //     printf("%d %c\n",l,ans[l]);
            if(l==r)break;
            res2[r].erase(res2[r].find(ans[l]));
            ans[r]=*res2[r].begin();
         //   printf("%d %c\n",r,ans[r]);
            l++,r--;
        }
        printf("! %s\n",ans);
        fflush(stdout);
    }
}
/*
     0   
     1   1
     2   3
     3 5  1 0 0
    4*/