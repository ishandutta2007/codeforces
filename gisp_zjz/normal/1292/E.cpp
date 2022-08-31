#include<bits/stdc++.h>
#define pb push_back
using namespace std;
string ans;
int _,n,s[55],re,x,ban,ok;
void work(string t){
    if (ok){
        //re=0;
        //return;
    }
    cout << "? " << t << endl; fflush(stdout);
    scanf("%d",&re); int len=t.size();
    if (re==-1) assert(0);
    for (int i=0;i<re;i++){
        int pos;scanf("%d",&pos);
        for (int j=0;j<len;j++) s[pos+j]=t[j];
    }
}
void answer(string t){
    ans=t;
    //cout << "! " << t << endl; fflush(stdout);
    ok=1;
}
void dfs(int x){
    //cout<<x<<' '<<s[x]<<endl;
    if (x==5){
        string t="";
        for (int i=1;i<=4;i++) t+=s[i];
        work(t);
        if (re) answer(t);
    } else if (s[x]!='?'){
        dfs(x+1);
    } else{
        s[x]='O'; dfs(x+1); s[x]='?';
        s[x]='H'; dfs(x+1); s[x]='?';
        if (!ban||x==4) s[x]='C',dfs(x+1),s[x]='?';
    }
}
void solve4(){
    int f=0;
    ans="????";
    work("CO"); f+=re;
    work("CH"); f+=re;
    if (f){
        ban=0;
        dfs(1);
    } else {
        work("OH"); f+=re;
        work("HO"); f+=re;
        if (f){
            if (s[3]=='?'){
                ban=0;
                s[3]='C';  dfs(4); s[3]='?';
                s[3]=s[2]; dfs(4); s[3]='?';
            } else {
                ban=1;
                dfs(1);
            }
        } else {
            work("HHH"); f+=re;
            work("OOO"); f+=re;
            work("CCC"); f+=re;
            if (f){
                if (s[1]=='?'){
                    if (s[4]=='C'){
                        work("OCCC");
                        if (re) answer("OCCC"); else answer("HCCC");
                    } else if (s[4]=='H'){
                        work("OHHH");
                        if (re) answer("OHHH"); else answer("CHHH");
                    } else {
                        work("COOO");
                        if (re) answer("COOO"); else answer("HOOO");
                    }
                } else if (s[4]=='?') {
                    if (s[1]=='C'){
                        work("CCCO");
                        if (re) answer("CCCO"); else answer("CCCH");
                    } else if (s[1]=='H'){
                        work("HHHO");
                        if (re) answer("HHHO"); else answer("HHHC");
                    } else {
                        work("OOOC");
                        if (re) answer("OOOC"); else answer("OOOH");
                    }
                } else {
                    string t="";
                    for (int i=1;i<=4;i++) t+=s[i];
                    answer(t);
                }
            } else {
                work("HHCC");
                if (re) answer("HHCC"); else answer("OOCC");
            }
        }
    }
    cout << "! " << ans << endl; fflush(stdout);
}
void solve(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) s[i]='?';
    if (n==4) {solve4();return;}
    work("CC");
    work("CH");
    work("CO");
    work("OH");
    work("HO");
    for (int i=2;i<n;i++)
        if (s[i-1]!='?'&&s[i]=='?') s[i]=s[i-1];

    bool flag=0;
    if (s[1]=='?'){
        int pos=1;
        for (int i=1;i<n;i++) if (s[i]=='?') pos=i;
        for (int i=1;i<=pos;i++) s[i]='H';
        string t;
        for (int i=1;i<n;i++) t+=s[i];
        work(t);
        if (re==0) {
            for (int i=1;i<=pos;i++) s[i]='O';
        }
    }
    if (s[n]=='?') flag=1;
    if (flag){
        s[n]=s[n-1];
        string t;
        for (int i=1;i<=n;i++) t+=s[i];
        work(t);
        if (re==0) s[n]='C';
    }
    printf("! ");
    for (int i=1;i<=n;i++) printf("%c",s[i]); puts("");
    fflush(stdout);
}

int main(){
    scanf("%d",&_);
    while (_--) {
        ok=0;solve();
        scanf("%d",&x);
        assert(x);
    }
}