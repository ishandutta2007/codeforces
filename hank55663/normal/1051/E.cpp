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
//#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define rank Rank
typedef long long LL;
char a[1000005];
char l[1000005];
char r[1000005];
int f[1000005];
int okl[1000005];
int okr[1000005];
int mod=998244353;

#define N 2000005
char ss[N];
int heigh[N];
int sa[N];  //res
int rank[N];
int length; //len
int val[30]; //weighted
int c[N]; 
int temp[2][N];
void suffix_array()
{
    int A = 250;          
    int* rank = temp[0];
    int* new_rank = temp[1];
    for (int i=0; i<A; ++i) c[i] = 0;
    for (int i=0; i<length; ++i) c[rank[i] = ss[i]]++;
    for (int i=1; i<A; ++i) c[i] += c[i-1];
    for (int i=length-1; i>=0; --i) sa[--c[ss[i]]] = i;
    for (int n=1; n<length; n*=2)
    {
        for (int i=0; i<A; ++i) c[i] = 0;
        for (int i=0; i<length; ++i) c[rank[i]]++;
        for (int i=1; i<A; ++i) c[i] += c[i-1];
        int* sa2 = new_rank;       
        int r = 0;                  
        for (int i=length-n; i<length; ++i)   
            sa2[r++] = i;           
        for (int i=0; i<length; ++i)    
            if (sa[i] >= n)       
                sa2[r++] = sa[i] - n;
        for (int i=length-1; i>=0; --i)
            sa[--c[rank[sa2[i]]]] = sa2[i];
        new_rank[sa[0]] = r = 0;
        for (int i=1; i<length; ++i)
        {
            if (!(rank[sa[i-1]] == rank[sa[i]] &&
                sa[i-1]+n < length &&    // stable sort trick
                rank[sa[i-1]+n] == rank[sa[i]+n]))
                r++;
            new_rank[sa[i]] = r;
        }
        swap(rank, new_rank);
        if (r == length-1) break;
        A = r + 1;
    }
}
void lcp_array()
{
    for (int i=0; i<length; ++i)
        rank[sa[i]] = i;
 
    for (int i=0, lcp=0,h=0; i<length; i++)
        if (rank[i] == 0)
            heigh[0] = 0;
        else
        {
            int j = sa[rank[i]-1];
            if (lcp > 0) lcp--;
            while (ss[i+lcp] == ss[j+lcp]) lcp++;
            heigh[rank[i]] = lcp;
        }
}

int dp[1000005];
int okzero;
int main(){
    scanf("%s",a);
    scanf("%s",l);
    if(l[0]=='0'&&l[1]==0)
    l[0]='1',okzero=1;
    scanf("%s",r);
    int lena=strlen(a),lenl=strlen(l),lenr=strlen(r);
    for(int i=0;a[i]!=0;i++)
    ss[i]=a[i];
    ss[lena]='$';
    for(int i=0;l[i]!=0;i++)
    ss[i+lena+1]=l[i];
    length=lena+lenl+1;
    ss[length]=0;
    suffix_array();
   // printf("%s\n",ss);
    int st=0;
    for(int i=0;i<length;i++){
        if(sa[i]==lena+1)
        st=i;
        /*printf("%d ",sa[i]);
        printf("\n");*/
    }
    lcp_array();
    int now=1e9;
    for(int i=st+1;i<length;i++){
        now=min(now,heigh[i]);
        if(sa[i]<lena){
            if(a[sa[i]+now]<l[now]){
                okl[sa[i]]=0;
            }
            else{
                okl[sa[i]]=1;
            }
        }
    }
    now=1e9;
    for(int i=st-1;i>=0;i--){
        now=min(heigh[i+1],now);
        if(sa[i]<lena){
            if(a[sa[i]+now]<l[now]){
                okl[sa[i]]=0;
            }
            else{
                okl[sa[i]]=1;
            }
        }
    }
   /* for(int i=0;i<lena;i++)
    printf("%d ",okl[i]);
    printf("\n");*/
    for(int i=0;r[i]!=0;i++)
    ss[i+lena+1]=r[i];
    length=lena+lenr+1;
    ss[length]=0;
    suffix_array();
   // printf("%s\n",ss);
    st=0;
    for(int i=0;i<length;i++){
        if(sa[i]==lena+1)
        st=i;
        /*printf("%d ",sa[i]);
        printf("\n");*/
    }
    lcp_array();
    now=1e9;
    for(int i=st+1;i<length;i++){
        now=min(now,heigh[i]);
        if(sa[i]<lena){
            if(a[sa[i]+now]<=r[now]||r[now]==0){
                okr[sa[i]]=1;
            }
            else{
                okr[sa[i]]=0;
            }
        }
    }
    now=1e9;
    for(int i=st-1;i>=0;i--){
        now=min(heigh[i+1],now);
        if(sa[i]<lena){
            if(a[sa[i]+now]<=r[now]||r[now]==0){
                okr[sa[i]]=1;
            }
            else{
                okr[sa[i]]=0;
            }
        }
    }
  /*  for(int i=0;i<lena;i++)
    printf("%d ",okr[i]);
    printf("\n");*/
    int l=0,r=-1;
    LL sum=0;
    if(lenl==1){
        if(okl[r+1]){
            if(a[r+1]!='0')
            sum+=1;//,printf("add %d \n",dp[r]);
            r++;
        }
    }
    for(int i=0;a[i]!=0;i++){
        dp[i]=sum;
        if(a[i]=='0'&&okzero){
           // printf("?\n");
            if(i==0)
            dp[i]++;
            else
            dp[i]+=dp[i-1];
            dp[i]%=mod;
        }
        //printf("%d\n",sum);
        while(1){
            if(i-r+1>lenl){
                if(a[r+1]!='0'){
                    if(r==-1)
                    sum++;
                    else
                    sum+=dp[r];//,printf("add %d \n",dp[r]);
                }
                r++;
            }
            else if(i-r+1==lenl){
                if(okl[r+1]){
                    if(a[r+1]!='0'){
                        if(r==-1)
                        sum++;
                        else
                        sum+=dp[r];//,printf("add %d \n",dp[r]);
                    }
                    r++;

                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
       // printf("sum: %d\n",sum);
        while(1){
          //  printf("%d %d %d\n",l,i-l,lenr);
            if(i-l+2>lenr){
                if(a[l]!='0'){
                    if(l==0)
                    sum--;//,printf("sub 1 \n");
                    else
                    sum-=dp[l-1];//,printf("sub %d \n",dp[l-1]);;
                }
                l++;
            }
            else if(i-l+2==lenr){
                if(!okr[l]){
                    if(a[l]!='0'){
                        if(l==0)
                        sum--;//,printf("sub 1 \n");
                        else
                        sum-=dp[l-1];//,printf("sub %d \n",dp[l-1]);;
                    }
                    l++;
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
        sum=(sum%mod+mod)%mod;
     //   printf("%d %d %d %d\n",dp[i],l,r,sum);
    }
    printf("%d\n",dp[lena-1]);
    return 0;
}