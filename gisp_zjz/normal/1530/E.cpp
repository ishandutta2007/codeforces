#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=1e6+10;
int _,n,p,cnt[26];
char s[maxn];

int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%s",s); n=strlen(s);
        memset(cnt,0,sizeof(cnt));
        for (int i=0;i<n;i++) cnt[s[i]-'a']++;
        p=0; while (!cnt[p]) ++p;
        int one=-1; for (int i=0;i<26;i++) if (cnt[i]==1){one=i;break;}
        if (one!=-1){
            string ans="";
            ans+=(char)('a'+one); cnt[one]--;
            for (int i=0;i<26;i++)
                for (int j=0;j<cnt[i];j++)
                    ans+=(char)('a'+i);
            cout << ans << endl;
        } else if (cnt[p]==n){
            printf("%s\n",s);
        } else if (cnt[p]<=1+(n-cnt[p]+1)){
            string S="";
            for (int i=p+1;i<26;i++)
                for (int j=0;j<cnt[i];j++)
                    S+=(char)('a'+i);
            int pos=0;
            string ans="";
            for (int i=0;i<cnt[p];i++){
                ans+=(char)('a'+p);
                if (i>0&&i<cnt[p]-1) ans+=S[pos],pos++;
            }
            for (int i=pos;i<S.size();i++) ans+=S[i];
            cout << ans << endl;
        } else {
            int q,r;
            q=p+1; while (!cnt[q]) ++q;
            r=q+1; while (r<26&&!cnt[r]) ++r;
            string ans="";
            if (r<26){
                ans+=(char)('a'+p);
                ans+=(char)('a'+q); cnt[q]--;
                for (int i=1;i<cnt[p];i++) ans+=(char)('a'+p);
                ans+=(char)('a'+r); cnt[r]--;
                for (int i=p+1;i<26;i++)
                    for (int j=0;j<cnt[i];j++)
                        ans+=(char)('a'+i);
            } else {
                ans+=(char)('a'+p);
                for (int i=0;i<cnt[q];i++) ans+=(char)('a'+q);
                for (int i=1;i<cnt[p];i++) ans+=(char)('a'+p);
            }
            cout << ans << endl;
        }
    }
    return 0;
}