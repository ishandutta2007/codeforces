/*#include<utility>
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

typedef long long LL;
queue<int> q[100005];
int main(){
    int n;
    scanf("%d",&n);
    int a[100005];
    int cnt[100005];
    fill(cnt,cnt+n+1,0);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        a[i]=n-a[i];
        cnt[a[i]]++;
    }

    int number=1;
    for(int i=1;i<=n;i++){
        if(cnt[i]%i!=0){
            printf("Impossible\n");
                return 0;
        }
        else{
            for(int j=0;j<cnt[i];j+=i){
                for(int k=0;k<i;k++){
                    q[i].push(number);
                }
                number++;
            }
        }
    }
    printf("Possible\n");
    for(int i=0;i<n;i++){
        printf("%d ",q[a[i]].front());
        q[a[i]].pop();
    }
}
/*
0 1 0
0 0 1
1 0 1
*/