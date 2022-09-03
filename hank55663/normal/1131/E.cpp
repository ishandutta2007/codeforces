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
    int n;
    scanf("%d",&n);
    LL seq[26];
    MEM(seq);
    char c[100005];
    int has[26];
    MEM(has);
    for(int t=0;t<n;t++){
        scanf("%s",c);
        int allsame=1;
        for(int j=0;c[j]!=0;j++)
        has[c[j]-'a']=1;
        for(int j=1;c[j]!=0;j++){
            if(c[j]!=c[j-1])
            allsame=0;
        }
        if(allsame){
            seq[c[0]-'a']=(seq[c[0]-'a']+1)*strlen(c)+seq[c[0]-'a'];
            for(int i=0;i<26;i++){
                if(seq[i]&&c[0]-'a'!=i){
                    seq[i]=1;
                }
            }
        }
        else{
            LL temp[26];
            MEM(temp);
            for(int j=0;j<26;j++)
            if(has[j])temp[j]=1;
            char type=c[0];
            LL cnt=1;
            for(int i=1;c[i]!=0;i++){
                if(c[i]==type)cnt++;
                else{
                    temp[type-'a']=max(temp[type-'a'],cnt);
                    cnt=1;
                    type=c[i];
                }
            }
            temp[type-'a']=max(temp[type-'a'],cnt);
            int len=strlen(c);
            if(c[0]==c[len-1]){
                if(seq[c[0]-'a']){
                    LL tot=1;
                    for(int i=0;c[i]!=0;i++){
                        if(c[i]==c[0])
                        tot++;
                        else
                        {
                            break;
                        }
                    }
                    for(int i=len-1;i>=0;i--){
                        if(c[i]==c[0])
                        tot++;
                        else
                        {
                            break;
                        }
                        
                    }
                    temp[c[0]-'a']=max(temp[c[0]-'a'],tot);
                }
                else{
                }
            }
            else{
                LL tot1=0,tot2=0;
                for(int i=0;c[i]!=0;i++){
                    if(c[i]==c[0])
                    tot1++;
                    else
                    {
                        break;
                    }
                }
                if(seq[c[0]-'a'])tot1++;
                for(int i=len-1;i>=0;i--){
                    if(c[i]==c[len-1])
                    tot2++;
                    else
                    {
                        break;
                    }
                }
                if(seq[c[len-1]-'a'])tot2++;
                temp[c[0]-'a']=max(temp[c[0]-'a'],tot1);
                temp[c[len-1]-'a']=max(temp[c[len-1]-'a'],tot2);
            }
            for(int i=0;i<26;i++)
            seq[i]=temp[i];
        }
    }
    LL Max=0;
    for(int i=0;i<26;i++)
    Max=max(Max,seq[i]);
    printf("%lld\n",Max);
}
/*

i f f x f l b
*/