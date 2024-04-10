#include <iostream> 
#include <list> 
#include <string>
#include <cmath>
#include <vector>
#include <fstream> 
using namespace std; 
class skill
{
public :   
    string name;  
    int value;     
    bool flag;    
    skill(){}  
    skill(string _name){name = _name;value = 0;flag = true;} 
};  

template <class T> void change(T &a, T &b)// 
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
void quicksort(vector<skill> &S,int a,int b) // 
{
     int x = a;
     int y = b;
     string mid = S[(a+b)>>1].name;
     while (x <= y)
     {
           while (S[x].name < mid) x++;
           while (S[y].name > mid) y--;
           if (x <= y)
           {
              change(S[x], S[y]);
              x++;
              y--;
           }
     }
     if (x < b) quicksort(S, x, b);
     if (y > a) quicksort(S, a, y);
}
 int main() 
 {      
     int n, m; 
     double k;  
     cin >> n >> m >> k;  
     vector <skill> svec(n);   
     for(int i = 0; i < n; i++)   
     {         
         cin >> svec[i].name >> svec[i].value;        
         svec[i].value = int(k*svec[i].value + 0.00000001);     
         svec[i].flag = true;  
         if(svec[i].value < 100)     
         {                  
             svec[i].value = 0;     
             svec[i].flag = false; 
         }        
     }       
     for(int i = 0; i < m; i++)  
     {             
         string str;         
         cin >> str;       
         bool flag = true;   
         for(int j = 0; j < n; j++)  
         {               
             if(str == svec[j].name)    
             {           
                 flag = false;  
                 svec[j].flag = true;    
                 break;       
             }            
         }            
         if(flag)svec.push_back(skill(str));  
     }     
     quicksort(svec,0, svec.size()-1); 
     int count = 0;  
     for(int i = 0; i < svec.size(); i++)  
     {            
         count += svec[i].flag;   
     }      
     cout << count << endl;  
     for(int i = 0; i < svec.size();i++)    
     {         
         if(svec[i].flag)    
             cout << svec[i].name << " " << svec[i].value << endl;  
     }    
     return 0;
 }