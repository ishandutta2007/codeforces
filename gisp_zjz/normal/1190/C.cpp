#include<bits/stdc++.h>
#define maxn 500050
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
int n,k,mxa,mxb,mna,mnb,mxal[maxn],mnar[maxn],mxbl[maxn],mnbr[maxn];
char s[maxn];
int main(){
    cin >> n >> k >> s;
    mxa=-1; mxb=-1; mna=-1; mnb=-1;
    for (int i=0;i<n;i++){
        if (s[i]=='0') mxa=i; else mxb=i;
        mxal[i]=mxa;
        mxbl[i]=mxb;
    }
    for (int i=n-1;i>=0;i--){
        if (s[i]=='0') mna=i; else mnb=i;
        mnar[i]=mxa;
        mnbr[i]=mxb;
    }
    if (mxa==-1||mxa-mna+1<=k){
        puts("tokitsukaze");
    } else if (mxb==-1||mxb-mnb+1<=k){
        puts("tokitsukaze");
    } else {
        bool flag=0;
        for (int i=0;i<=n-k;i++){
            int mn,mx;
            if (mnb<i) mn=mnb; else mn=mnbr[i+k];
            if (mxb>=i+k) mx=mxb; else mx=mxbl[i-1];
            if (mx-mn+1>k) flag=1;
            if (mna<i) mn=mna; else mn=mnar[i+k];
            if (mxa>=i+k) mx=mxa; else mx=mxal[i-1];
            if (mx-mn+1>k) flag=1;
        }
        if (flag) puts("once again");
        else puts("quailty");
    }
    return 0;
}