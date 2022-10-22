// package Codeforces.Div3Aug18;

//import java.util.HashMap;
//import java.util.Scanner;
//import java.util.TreeMap;
#include <bits/stdc++.h>
using namespace std;

//public class E {
int main() {
  cin.tie(0)->sync_with_stdio(0); // fast input

  //Scanner sc = new Scanner(System.in);
  //int te = sc.nextInt();
  int te;
  cin >> te;
  //sc.nextLine();
  for (int i = 0; i < te; i++) {
    //String T = sc.nextLine();
    //char[] t = T.toCharArray();
    string t;
    cin >> t;
    //HashMap<Character,Integer> freq = new HashMap<>();
    //TreeMap<Integer,Character> lastOcc = new TreeMap<>();
    unordered_map<char, int> freq;
    map<int, char> lastOcc;

    //for(int a=t.length-1;a>-1;a--){
    for(int a=t.size()-1;a>-1;a--){
      char c = t[a];
      //if(!lastOcc.containsValue(c)) lastOcc.put(a,c);
      //freq.put(c,freq.getOrDefault(c,0)+1);
      if(freq[c] == 0) lastOcc[a] = c;
      freq[c] += 1;
    }
    int lengththeory=0;
    //String removeOrder = "";
    string removeOrder;
    //            System.out.println(lastOcc);
    //            System.out.println(freq);
    int acc = 1;
    //while(!lastOcc.keySet().isEmpty()){
    while(!lastOcc.empty()) {
      //removeOrder += lastOcc.firstEntry().getValue();
      removeOrder += lastOcc.begin()->second;
      //lengththeory += freq.get(lastOcc.firstEntry().getValue())/(acc);
      lengththeory += freq[lastOcc.begin()->second] / acc;
      //lastOcc.remove(lastOcc.firstKey());
      lastOcc.erase(lastOcc.begin());
      acc++;
    }
    //            System.out.println(lengththeory + " " + removeOrder);
    //if(t.length<lengththeory){
    if(t.size()<lengththeory){
      //System.out.println(-1);
      cout << -1 << '\n';
      continue;
    }
    //String sguess = T.substring(0,lengththeory);
    //String so = sguess;
    string sguess = t.substr(0, lengththeory);
    string so = sguess;
    //            System.out.println(sguess);
    // construct s
    //String simulatedT = "";
    string simulatedT;
    //for(int a=0;a<removeOrder.length();a++){
    for(int a=0;a<removeOrder.size();a++){
      simulatedT += sguess;
      //sguess=sguess.replace(String.valueOf(removeOrder.charAt(a)),"");
      string transformed;
      for (char c : sguess) {
        if (c == removeOrder[a]) continue;
        transformed.push_back(c);
      }
      sguess = transformed;
      //                System.out.println(simulatedT);

    }
    //if(simulatedT.equals(T)){
    if(simulatedT == t){
      //System.out.println(so + " " + removeOrder);
      cout << so << " " << removeOrder << '\n';
    } else {
      //System.out.println(-1);
      cout << -1 << '\n';
    }
  }

  return 0;
}
//}