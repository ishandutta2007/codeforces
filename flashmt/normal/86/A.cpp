    #include<iostream>
         #include<algorithm>
         using namespace std;
      
         long long re,t,l,r;
      
         int main()
         {
          cin >> l >> r;
          t=9;
          while (t<r) t=t*10+9;
          re=r*(t-r);
         re=max(re,l*(t-l));
          t/=2;
       if (r>=t && l<=t+1) re=max(re,t*(t+1));
         cout << re << endl;    
          return 0;
         }