                          #include<bits/stdc++.h>
                using namespace std;int T, DONUTS_ARE_fake;
            int cake_is_real[63]; int this_is_a_triumph[59][61];
         int main(int $960_70,char**donutdonutdonutdonutdonutdonut){
       int experiment;cin>>experiment; int n; auto moist=cake_is_real;
      while(cin>>n){cin>>(char*)cake_is_real; vector<int> draws_for_$$$;
     for(int kaktus=0;kaktus                         <n;kaktus++){char*z=
     (char*)(moist+kaktus/4                           );if(*(z+ kaktus%4)
      =='2'){draws_for_$$$.                          push_back(kaktus);}}
      if(size(draws_for_$$$                          )-1<=1){puts("NO");
        continue;}memset(this_is_a_triumph,0,sizeof this_is_a_triumph);
         auto&d=draws_for_$$$;auto&g =this_is_a_triumph;int m=size(d);
           for(int i=0;i<m;i++){int j=(i+1)%m;g[d[i]][d[j]]=1;g[d[j]]
             [d[i]]=2;}puts("YES");for(int i=0;i<n;i++)for(int j=0;
                j<n;j++)cout<<(i==j?'X':g[i][j]==1?'+':g[i][j]?
                    '-':'=')<<(j+1==n?"\n":"");}return 0;}