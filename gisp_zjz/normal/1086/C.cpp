#include<bits/stdc++.h>
#define maxn 1000500
using namespace std;
char s[maxn],t[maxn],w[maxn];
int n,k,f[26],T,a[maxn],b[maxn],c[maxn];
bool v[26];

void pt(bool flag){
    if (flag){
        puts("YES");
        int j=0;
        for (int i=0;i<k;i++) if (f[i]==-1){
            while (v[j]) j++;
            f[i]=j++;
        }
        for (int i=0;i<k;i++) printf("%c",'a'+f[i]); puts("");
    } else puts("NO");
}

bool tryup(int x){
    for (int i=x;i<n;i++){
        if (f[c[i]]!=-1){
            if (f[c[i]]==a[i]) continue;
            return f[c[i]]>a[i];
        } else {
            for (int j=a[i]+1;j<k;j++) if (!v[j]){
                f[c[i]]=j; v[j]=1;
                return true;
            }
            if (!v[a[i]]){
                f[c[i]]=a[i]; v[a[i]]=1; continue;
            }
            return false;
        }
    }
    return true;
}

bool trydown(int x){
    for (int i=x;i<n;i++){
        if (f[c[i]]!=-1){
            if (f[c[i]]==b[i]) continue;
            return f[c[i]]<b[i];
        } else {
            for (int j=0;j<b[i];j++) if (!v[j]){
                f[c[i]]=j; v[j]=1;
                return true;
            }
            if (!v[b[i]]){
                v[b[i]]=1; f[c[i]]=b[i]; continue;
            }
            return false;
        }
    }
    return true;
}

void solve(){
    memset(f,-1,sizeof(f));
    memset(v,0,sizeof(v));
    scanf("%d",&k);
    scanf("%s%s%s",w,s,t); n=strlen(s);
    for (int i=0;i<n;i++) a[i]=s[i]-'a',b[i]=t[i]-'a',c[i]=w[i]-'a';
    for (int i=0;i<n;i++){
        if (a[i]==b[i]){
            if (f[c[i]]!=-1&&f[c[i]]!=a[i]) {pt(0); return;}
            if (f[c[i]]==-1&&v[a[i]]) {pt(0); return;}
            v[a[i]]=1; f[c[i]]=a[i];
            continue;
        }
        if (f[c[i]]!=-1){
            if (f[c[i]]>a[i]&&f[c[i]]<b[i]) pt(1);
            else if (f[c[i]]==a[i]){
                pt(tryup(i+1));
            } else if (f[c[i]]==b[i]){
                pt(trydown(i+1));
            } else pt(0);
            return;
        } else {
            for (int j=a[i]+1;j<b[i];j++)
            if (!v[j]){
                v[j]=1; f[c[i]]=j; pt(1);
                return;
            }
            int tmp[26],vtmp[26];
            for (int j=0;j<k;j++) tmp[j]=f[j],vtmp[j]=v[j];
            if (!v[a[i]]) {
                v[a[i]]=1; f[c[i]]=a[i];
                if (tryup(i+1)) {pt(1); return;}
            }
            for (int j=0;j<k;j++) f[j]=tmp[j],v[j]=vtmp[j];
            if (!v[b[i]]) {
                v[b[i]]=1; f[c[i]]=b[i];
                if (trydown(i+1)) {pt(1); return;}
            }
            pt(0); return;
        }
    }
    pt(1);
}

int main(){
    cin >> T;
    while (T--) solve();
    return 0;
}