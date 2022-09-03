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
    if(n==1){
        for(int i = 0;i<26;i++){
            if(cnt[i])
                res[0].insert(i+'a');
        }
        return res;
    }
    if(n==2){
        for(int i = 0;i<26;i++){
            for(int j=0;j<cnt[i];j++){
                res[0].insert(i+'a');
                res[1].insert(i+'a');
            }
        }
        return res;
    }
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
    /*char cc[12]="rnnnqnnrn";
    for(int i = 0;i<9;i++){
        for(int j=i;j<9;j++){
            for(int k=i;k<=j;k++)
            printf("%c",cc[k]);
            printf("\n");
        }
    }*/
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
    else if(n==3){
        printf("? 1 1\n");
        fflush(stdout);
        char c1,c2,c3;
        scanf(" %c",&c1);
        printf("? 2 2\n");
        fflush(stdout);
        scanf(" %c",&c2);
        printf("? 3 3\n");
        fflush(stdout);
        scanf(" %c",&c3);
        printf("! %c%c%c\n",c1,c2,c3);
        fflush(stdout);
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
        printf("? 1 %d\n",n/2);
        fflush(stdout);
       // vector<string> v;
        string tmp2;
        for(int i = 1;i<=n/2;i++){
            for(int j=i;j<=n/2;j++){
                char c[105];
                scanf("%s",c);
                if(strlen(c)>tmp2.size())
                tmp2=string(c);
                v.pb(string(c));
            }
        }
        vector<multiset<char> > res2=cal(v,n/2);
        v.clear();
        int tl=n/2+1,tr=n-1;
        if(n%2==1)tl++;
        printf("? %d %d\n",tl,tr);
        fflush(stdout);
       // vector<string> v;
        string tmp3;
        for(int i = tl;i<=tr;i++){
            for(int j=i;j<=tr;j++){
                char c[105];
                scanf("%s",c);
                if(strlen(c)>tmp3.size())
                tmp3=string(c);
                v.pb(string(c));
            }
        }
        
        vector<multiset<char> > res3(n/2);
        if(n%2==1)
        res3.pb(multiset<char>());
        for(auto it:cal(v,tr-tl+1))
            res3.pb(it);
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
        for(auto it:tmp3){
            cnt[it-'a']--;
        }
                int tot=1;
        if(n%2==1)
        {
            ans[n/2]=*res1[n/2].begin();
            tot++;
            cnt[ans[n/2]-'a']--;
        }
        for(int i = 0;i<26;i++){
            if(cnt[i])ans[n-1]=i+'a';
        }
        int l=0,midl=n/2-1,midr=tl-1,r=tr-1;

       /* for(auto it:res1){
            for(auto it2:it){
                printf("%c ",it2);
            }
            printf("\n");
        }
        for(auto it:res2){
            for(auto it2:it){
                printf("%c ",it2);
            }
            printf("\n");
        }
        for(auto it:res3){
            for(auto it2:it){
                printf("%c ",it2);
            }
            printf("\n");
        }*/
        while(l<=r){
          //  printf("%d %d %d %d %c\n",l,midl,midr,r,ans[r+1]);
            res1[l].erase(res1[l].find(ans[r+1]));
            ans[l]=*res1[l].begin();
            tot++;
            if(tot==n)
            break;
          //  printf("%d %d %d %d\n",l,midl,midr,r);
            if(res2[midl].size()==2)
            res2[midl].erase(res2[midl].find(ans[l]));
            ans[midl]=*res2[midl].begin();
            tot++;
            if(tot==n)
            break;
           // printf("%d %d %d %d %d %c\n",l,midl,midr,r,res3[midr].size(),ans[midl]);
            if(res1[midr].size()==2)
            res1[midr].erase(res1[midr].find(ans[midl]));
            ans[midr]=*res1[midr].begin();
            tot++;
            if(tot==n)
            break;
           // printf("%d %d %d %d %d %c\n",l,midl,midr,r,tot,ans[midr]);
        if(res3[r].size()==2)
            res3[r].erase(res3[r].find(ans[midr]));
            ans[r]=*res3[r].begin();
            tot++;
            if(tot==n)
            break;
          //  printf("%d %d %d %d %d\n",l,midl,midr,r,tot);
            l++,r--;
            midl--;
            midr++;
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