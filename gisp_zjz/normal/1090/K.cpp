#include<bits/stdc++.h>
#define maxn 1000005

using namespace std;
typedef pair<string,int> pi;
typedef vector<int> vi;
char s[maxn],t[maxn];
string tt;
int n,len,res;
map <pi,vi> f;

int main(){
    cin >> n;
    for (int i=1;i<=n;i++){
        scanf("%s%s",s,t);
        len=strlen(t); res=0;
        for (int j=0;j<len;j++) res|=1<<(t[j]-'a');
        len=strlen(s);
        while (len>0&&(res&(1<<(s[len-1]-'a')))) len--;
        tt="";
        for (int i=0;i<len;i++) tt+=s[i];
        f[(pi){tt,res}].push_back(i);
    }
    cout << f.size() << endl;
    for (auto &u:f){
        vi a=u.second; cout << a.size();
        for (int i=0;i<a.size();i++) cout << ' ' << a[i]; puts("");
    }
    return 0;
}