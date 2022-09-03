#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
bool cmp(const string &a, const string &b){
    string s1=a+b;
    string s2=b+a;
    return s1<s2;
    //return a.size()<b.size();
}
/*struct node{
    node *n[26];
    int cnt[26];
    node(){
        fill(cnt,cnt+26,0);
        MEM(n);
    }
}*root;
void add(string &s){
    node *n=root;
    for(int i = 0;i<s.size();i++){
        if(!n->n[s[i]-'a']){
            n->n[s[i]-'a'] = new node();
        }
    }
}*/
int main(){
    int n;
    scanf("%d",&n);
    string s[50005];
    for(int i = 0;i<n;i++){
        char c[50005];
        scanf("%s",c);
        s[i]=string(c);
    }
    sort(s,s+n,cmp);
    for(int i = 0;i<n;i++){
        printf("%s",s[i].c_str());
    }
    printf("\n");
}