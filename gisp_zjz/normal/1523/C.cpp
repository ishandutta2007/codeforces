#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
const int M=998244353;
int a[maxn],_,n,t,x;
void print(){
    for (int i=1;i<t;i++) printf("%d.",a[i]);printf("%d\n",a[t]);
}
int main(){
    cin >> _;
    while (_--){
        cin >> n;
        t=0; for (int i=1;i<=n;i++) a[i]=0;
        while (n--){
            cin >> x;
            int pos=t+1;
            while (pos>0&&a[pos]+1!=x) a[pos]=0,pos--;
            assert(pos>0);
            a[pos]++; t=pos;
            print();
        }
    }
    return 0;
}