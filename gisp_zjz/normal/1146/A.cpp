#include<bits/stdc++.h>
#define maxn 300050
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
char s[maxn];
int main(){
    scanf("%s",s);
    int n=strlen(s);
    int c=0;
    for (int i=0;i<n;i++) c+=s[i]=='a';
    printf("%d\n",min(n,c*2-1));
    return 0;
}