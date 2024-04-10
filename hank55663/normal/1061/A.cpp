#include<bits/stdc++.h>
#define LL long long 
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pb push_back
#define y second
#define x first
#define mp make_pair
#define pii pair<int,int>
int main(){
    int n,s;
    scanf("%d %d",&n,&s);
    printf("%d\n",s/n+(s%n!=0));
}