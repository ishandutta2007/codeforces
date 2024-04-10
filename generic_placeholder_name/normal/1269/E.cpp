#include<iostream>
#include<ext/pb_ds/assoc_container.hpp>
#define L long long
#define r(n) for(L i=1;i<=n;i++)
using namespace std;using namespace __gnu_pbds;tree<L,null_type,less<L>,rb_tree_tag,tree_order_statistics_node_update>S;L A[333333],P[333333],n,a;int main(){cin>>n;r(n)cin>>A[i],P[A[i]]=i;r(n){L c=S.order_of_key(P[i]);a+=i-c-1-min(c,i-c-1);L m=((i-1)/2)+1;if(m<=c)a+=P[i]+m-*S.find_by_order(m-1)-c-1;m=i/2;if(m>c)a+=*S.find_by_order(m-1)+c-P[i]-m;S.insert(P[i]);cout<<a<<' ';}}