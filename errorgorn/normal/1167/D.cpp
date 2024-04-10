#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
int n,k,mk;
stack<char> s;
char c;
int arr[200005];
int main(){
    scanf("%d",&n);
    getchar();
    for (int x=0;x<n;x++){
        c=getchar();
        if (!s.empty() && s.top()=='(' && c==')'){
            s.pop();
            arr[x]=k--;
        }
        else{
            s.push(c);
            arr[x]=++k;
        }
        mk=max(mk,k);
    }
    mk>>=1;
    for (int x=0;x<n;x++){
        printf("%d",arr[x]>mk);
    }
}