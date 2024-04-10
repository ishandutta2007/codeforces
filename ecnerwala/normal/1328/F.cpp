#include<bits/stdc++.h>
using namespace std;
int64_t N,K,i,a,b,c,d,A[1<<19];main(){for(cin>>N>>K,i=N;i--;cin>>A[i]);for(sort(A,A+N--),K--;i++<K;a+=A[K]-A[i],b+=A[N-i]-A[N-K],c+=abs(A[N/2]-A[i]));for(--i;i++<N;d+=A[i]==A[i-K],a-=A[i]==A[K],b-=A[N-i]==A[N-K],c+=abs(A[N/2]+1-A[i]));cout<<(d?0:min({a,b,c}));}