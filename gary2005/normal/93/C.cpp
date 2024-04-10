#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define PB push_back
#define ALL(a) a.begin(),a.end()
#define POB pop_back
using namespace std;
/*}
*/
vector<string> vec(6),tmp;int a[10],n;string get(int a,int k,int b){/*a=k*b*/string str;str="lea e";str+=char('a'+a-1);str+="x, [";str+=char('0'+k);str+="*e";str+=char('a'+b-1);str+="x]";return str;}string get2(int a,int b,int k,int c){/*a=b+ k*c*/string str;str="lea e";str+=char('a'+a-1);str+="x, [e";str+=char('a'+b-1);str+="x + ";str+=char('0'+k);str+="*e";str+=char('a'+c-1);str+="x]";return str;}void dfs(int to){rb(i,1,to) if(a[i]==n){vec=tmp;return;}if(tmp.size()+1>=vec.size()) return ;rb(i,1,to)rb(j,1,to)for(int k=1;k<=8;k<<=1){tmp.PB(get2(to+1,i,k,j));a[to+1]=a[i]+k*a[j];dfs(to+1);tmp.POB();}rb(j,1,to) for(int k=1;k<=8;k<<=1){tmp.PB(get(to+1,k,j));a[to+1]=k*a[j];dfs(to+1);tmp.POB();}}int main(){scanf("%d",&n);a[1]=1;dfs(1);cout<<vec.size()<<endl;for(auto it:vec){cout<<it<<endl;}return 0;}