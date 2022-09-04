
#include<bits/stdc++.h>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    printf("%d %d\n",0,0);
    fflush(stdout);
    string s;
    cin>>s;
    int l=1,r=1e9;
    for(int i=1;i<n;i++){
        int mid=(l+r)/2;
        printf("%d %d\n",mid,mid);
        fflush(stdout);
        string s2;
        cin>>s2;
        if(s2==s){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    printf("%d %d %d %d\n",l-1,l,l,l-1);
}