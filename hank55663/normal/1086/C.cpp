
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
int main(){
    int t;
    scanf("%d",&t);
    char s[1000005];
    char a[1000005];
    char b[1000005];
    while(t--){
        int k;
        scanf("%d",&k);
        int ans[26];
        int use[26];
        fill(ans,ans+26,-1);
        fill(use,use+26,0);
        int ok=1;
        scanf("%s",s);
        scanf("%s",a);
        scanf("%s",b);
        for(int i=0;s[i]!=0;i++){
            if(a[i]==b[i]){
                if(ans[s[i]-'a']==-1){
                    if(!use[a[i]-'a']){
                        ans[s[i]-'a']=a[i]-'a';
                        use[a[i]-'a']=1;
                    }
                    else{
                        ok=0;
                    }
                }
                else if(ans[s[i]-'a']!=a[i]-'a'){
                    ok=0;
                }
            }
            else{
               // printf("?\n");
                if(ans[s[i]-'a']==-1){
                    int ook=0;
                    for(int kk=a[i]-'a'+1;kk<b[i]-'a';kk++){
                        if(!use[kk]){
                            ans[s[i]-'a']=kk;
                            use[kk]=1;
                            ook=1;
                            break;
                        }
                    }
                    if(!ook){
                        int tempans[26],tempuse[26];
                        for(int i=0;i<k;i++){
                            tempans[i]=ans[i];
                            tempuse[i]=use[i];
                        }
                        if(!use[a[i]-'a']){
                            ans[s[i]-'a']=a[i]-'a';
                            use[a[i]-'a']=1;
                            if(s[i+1]==0)
                            ook=1;
                            for(int j=i+1;s[j]!=0;j++){
                                if(ans[s[j]-'a']==-1){
                                    for(int kk=a[j]-'a'+1;kk<k;kk++){
                                        if(!use[kk]){
                                            ans[s[j]-'a']=kk;
                                            ook=1;
                                            use[kk]=1;
                                            break;
                                        }
                                    }
                                    if(ook) break;
                                    if(!use[a[j]-'a']) ans[s[j]-'a']=a[j]-'a',use[a[j]-'a']=1;
                                    else    break;
                                }
                                else if(ans[s[j]-'a']>a[j]-'a'){ook=1;break;}
                                else if(ans[s[j]-'a']<a[j]-'a') break;
                                if(s[j+1]==0)   ook=1;
                            }
                        }
                        if(ook){
                            break;
                        }
                        for(int i=0;i<k;i++){
                            ans[i]=tempans[i];
                            use[i]=tempuse[i];
                        }
                        if(!use[b[i]-'a']){
                            ans[s[i]-'a']=b[i]-'a';
                            use[b[i]-'a']=1;
                            if(s[i+1]==0)
                            ook=1;
                            for(int j=i+1;s[j]!=0;j++){
                                 if(ans[s[j]-'a']==-1){
                                    for(int kk=b[j]-'a'-1;kk>=0;kk--){
                                        if(!use[kk]){
                                            ans[s[j]-'a']=kk;
                                            ook=1;
                                            use[kk]=1;
                                            break;
                                        }
                                    }
                                    if(ook) break;
                                    if(!use[b[j]-'a']) ans[s[j]-'a']=b[j]-'a',use[b[j]-'a']=1;
                                    else    break;
                                }
                                else if(ans[s[j]-'a']>b[j]-'a') break;
                                else if(ans[s[j]-'a']<b[j]-'a'){ook=1; break;}
                                if(s[j+1]==0)   ook=1;
                            }
                        }
                    }
                    if(!ook)
                    ok=0;
                }
                else{
                    int x=ans[s[i]-'a'];
                    if(x<a[i]-'a')
                    ok=0;
                    else if(x==a[i]-'a'){
                        int ook=0;
                        if(s[i+1]==0)ook=1;
                        for(int j=i+1;s[j]!=0;j++){
                            if(ans[s[j]-'a']==-1){
                                for(int kk=a[j]-'a'+1;kk<k;kk++){
                                    if(!use[kk]){
                                        ans[s[j]-'a']=kk;
                                        ook=1;
                                        use[kk]=1;
                                        break;
                                    }
                                }
                                if(ook) break;
                                if(!use[a[j]-'a']) ans[s[j]-'a']=a[j]-'a',use[a[j]-'a']=1;
                                else    break;
                                
                            }
                            else if(ans[s[j]-'a']>a[j]-'a'){ook=1;break;}
                            else if(ans[s[j]-'a']<a[j]-'a') break;
                            if(s[j+1]==0)   ook=1;
                        }
                        if(!ook)
                            ok=0;
                    }
                    else if(x>a[i]-'a'&&x<b[i]-'a'){

                    }
                    else if(x==b[i]-'a'){
                        int ook=0;//ans[s[i]-'a']=b[i]-'a';
                        if(s[i+1]==0)ook=1;
                        for(int j=i+1;s[j]!=0;j++){
                                if(ans[s[j]-'a']==-1){
                                for(int kk=b[j]-'a'-1;kk>=0;kk--){
                                    if(!use[kk]){
                                        ans[s[j]-'a']=kk;
                                        ook=1;
                                        use[kk]=1;
                                        break;
                                    }
                                }
                                if(ook) break;
                                if(!use[b[j]-'a']) ans[s[j]-'a']=b[j]-'a',use[b[j]-'a']=1;
                                else    break;
                                
                            }
                            else if(ans[s[j]-'a']>b[j]-'a') break;
                            else if(ans[s[j]-'a']<b[j]-'a'){ook=1; break;}
                            if(s[j+1]==0)   ook=1;
                        }
                        if(!ook)ok=0;
                    }
                    else
                        ok=0;
                }
                break;
            }
        }
        if(ok){
            printf("YES\n");
            set<int> s;
            for(int i=0;i<k;i++){
                if(!use[i])
                s.insert(i);
            }
            for(int i=0;i<k;i++){
                if(ans[i]==-1){
                    printf("%c",*s.begin()+'a');
                    s.erase(s.begin());
                }
                else{
                    printf("%c",ans[i]+'a');
                }
            }
            printf("\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}