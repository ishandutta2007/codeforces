#include<bits/stdc++.h>
#define maxn 505050

using namespace std;
char s[maxn];
string p[maxn],t[maxn],tt[maxn],a,b;
int n,flag,L[maxn];

int main(){
    while (true){
        scanf("%s",s);
        if (strncmp(s,"\\cite",5)==0){
            ++n;
            for (int i=6;s[i]!='}';i++) p[n]+=s[i];
        }
        if (strncmp(s,"\\begin",6)==0) break;
    }
    int len=strlen(s);
    for (int i=0;i<len;i++) a+=s[i];
    for (int i=0;i<=n;i++) getline(cin,t[i]);
    for (int i=1;i<=n;i++){
        int pos=0;
        while (t[i][pos]!='}') pos++;
        L[i]=pos-9;
    }
    //for (int i=1;i<=n;i++) cout << p[i] << endl;
    //for (int i=1;i<=n;i++) cout << t[i].substr(9,L[i]) << endl;
    for (int i=1;i<=n;i++){
        int pos=-1;
        for (int j=1;j<=n;j++) if (t[i].substr(9,L[i])==p[j]) pos=j;
        flag|=(pos!=i);
        assert(pos!=-1);
        tt[pos]=t[i];
    }

    cin >> b;
    if (flag){
        puts("Incorrect");
        cout << a << endl;
        for (int i=1;i<=n;i++) cout << tt[i] << endl;
        cout << b << endl;
    } else puts("Correct");
    return 0;
}