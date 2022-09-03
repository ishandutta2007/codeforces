#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long
#define ULL unsigned long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define pi acos(-1)
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
inline void manacher(char *s,int len,int *z){
	int l=0,r=0;
	for(int i=1;i<len;++i){
		z[i]=r>i?min(z[2*l-i],r-i):1;
		while(s[i+z[i]]==s[i-z[i]])++z[i];
		if(z[i]+i>r)r=z[i]+i,l=i;
	}
}
int z[2000005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char c[1000005];
        scanf("%s",c);
        /*for(int i = 0;i<100;i++){
            c[i]=rand()%2+'a';
            c[i+1]=0;
        }
        printf("%s\n",c);*/
        char cc[2000005];
        /*int aa=0;
        {
            string s(c);
            string ans;
            for(int i = 0;i<=s.size();i++){
                for(int j = i+1;j<=s.size();j++){
                    string s2=s.substr(0,i)+s.substr(j,s.size()-j);
                    string s3=s2;
                    reverse(s3.begin(),s3.end());
                    if(s2==s3&&s2.size()>ans.size()){
                        ans=s2;
                    }
                }
            }
            cout<<ans<<endl;
            aa=ans.size();
        }*/
        int Maxp=0;
        int l=0,r=strlen(c)-1;
        while(l<r){
            if(c[l]==c[r])Maxp++;
            else break;
            l++,r--;
        }
        if(l>=r){
            printf("%s\n",c);
            continue;
        }
        cc[0]='$';
        int len;
        for(int i = 0;c[i]!=0;i++){
            cc[i*2+1]=c[i];
            cc[i*2+2]='$';
            len=i*2+3;
        }
        cc[len-1]='$';
        cc[len]='#';
        cc[len+1]=0;
        len++;
        /*for(int i = 0;cc[i]!=0;i++)
        printf(" %c",cc[i]);
        printf("\n");*/
        manacher(cc,len,z);
        int Max=0,Maxi;
        for(int i = 0;cc[i]!=0;i++){
          //  if(cc[i]>='a'&&cc[i]<='z')z[i]--;
           // else z[i]--;
            int head=(i-z[i]+1)/2,tail=(len-z[i]-i)/2;
           // pr
           int val=min(head,tail)*2+z[i];
          val--;
            if(min(head,tail)<=Maxp&&Max<val){
                //if(cc[i]>='a'&&cc[i]<='z')
                
                Max=val;
                Maxi=i;
            }
        //    printf("%2d",z[i]);
          //  printf("%d %d %d %d %d %d\n",i,z[i],head,tail,Maxp,Maxi);
        }
      //  printf("\n");
        int head=(Maxi-z[Maxi]+1)/2,tail=(len-z[Maxi]-Maxi)/2;
        for(int i=0;i<min(head,tail);i++){
            printf("%c",c[i]);
        }
        for(int i=Maxi-z[Maxi]+1;i<Maxi+z[Maxi];i++){
            if(cc[i]!='#'&&cc[i]!='$'&&cc[i]!='!'){
                printf("%c",cc[i]);
            }
        }
        int len2=strlen(c);
        for(int i = min(head,tail)-1;i>=0;i--){
            printf("%c",c[len2-i-1]);
        }
        printf("\n");
        //printf("%d %d %d %d %d %d\n",aa,Max,head,tail,Maxi,z[Maxi]);
        //assert(aa==Max);
    }
}
/*

5
AACCMMAA
A
AA
MM
ACA
ACMAA


5
0 9 7 1 100
-1 0 -1 -1 91
-1 5 0 -1 96
-1 8 9 0 99
-1 -1 -1 -1 0
3 4
3 5
5 6
5 7
3 or 4
3 or 5
5 or 6
5 or 7

dp[x]=max(dp[x-w_i*j]+j*t_i-delta t_i*j*(j-1)/2)
dp[x]=max(dp[j]+x*t_i-j*t_i-delta t_i*(x-j)*(x-j-1)/2)
dp[x]=max(dp[j]-j*t_i-delta t_i *(j^2/2+j/2) - 
        delta t_i * xj + x*t_i + delta t_i * (x^2/2-x/2))
dp[x]=max(dp[j] + g(j) - delta t_i *xj + w(i) )
g(j)= dp[j]-j*t_i-delta t_i *(j^2/2+j/2)
w(i)=  x*t_i + delta t_i * (x^2/2-x/2)
x^2/2 -xj -x/2  +j^2/2 +j/2
*/

/*
 

*/