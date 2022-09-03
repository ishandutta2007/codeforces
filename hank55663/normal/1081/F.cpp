/*
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iostream>
#include<string.h>*/
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL ;
int main(){
    int n,t;
    scanf("%d %d",&n,&t);
    if(n%2==1){
        int sum[305];
        for(int i=1;i<n;i++){
            if(i%2==1){
                int now;
                int ans=-1;
                int s=n-i;
                for(int tt=0;;tt++){
                    printf("? %d %d\n",i+1,n);
                    fflush(stdout);
                    scanf("%d",&now);
                    if(tt%2==0&&now!=n-t){
                        ans=now;
                    }
                    if(ans!=-1&&tt%2==1&&now==t){
                        break;
                    }
                }
                if(ans==-1)ans=n-t;
                sum[i]=t-(t+s-ans)/2;
            }
            else{
                int now;
                int ans=-1;
                int s=i;
                for(int tt=0;;tt++){
                    printf("? 1 %d\n",i);
                    fflush(stdout);
                    scanf("%d",&now);
                    if(tt%2==0&&now!=n-t){
                        ans=now;
                    }
                    if(ans!=-1&&tt%2==1&&now==t){
                        break;
                    }
                }
                if(ans==-1)ans=n-t;
                sum[i]=(t+s-ans)/2;
            }
        }
        sum[n]=t;
        printf("! ");
        if(sum[1]==0)
        printf("0");
        else
        printf("1");
        for(int i=2;i<=n;i++){
            if(sum[i]==sum[i-1])
            printf("0");
            else
            printf("1");
        }
        printf("\n");
        fflush(stdout);
    }
    else{
        int sum[305];
        for(int i=1;i<n;i++){
            if(i%2==1){
                int now;
                int ans=-1;
                int s=i;
                for(int tt=0;;tt++){
                    printf("? 1 %d\n",i);
                    fflush(stdout);
                    scanf("%d",&now);
                    if(tt%2==0&&now!=n-t){
                        ans=now;
                    }
                    if(ans!=-1&&tt%2==1&&now==t){
                        break;
                    }
                }
                sum[i]=(t+s-ans)/2;
            }
            else{
                int now;
                int ans=-1;
                for(int tt=0;;tt++){
                    printf("? %d %d\n",i,i);
                    fflush(stdout);
                    scanf("%d",&now);
                    if(tt%2==1&&now!=t){
                        ans=(n-now+t-1)/2;
                    }
                    if(ans!=-1&&tt%2==1&&now==t){
                        break;
                    }
                }
                sum[i]=t-ans+sum[i-1];
            }
        }
        sum[n]=t;
        printf("! ");
        if(sum[1]==0)
        printf("0");
        else
        printf("1");
        for(int i=2;i<=n;i++){
            if(sum[i]==sum[i-1])
            printf("0");
            else
            printf("1");
        }
        printf("\n");
        fflush(stdout);
    }
}