    import java.io.*;
    import java.util.Arrays;
    import java.util.StringTokenizer;
     
    public class NubianMarket {
        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
            StringTokenizer st = new StringTokenizer(br.readLine());
            long[] souvenirs = new long[Integer.parseInt(st.nextToken())];
            int budget = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < souvenirs.length; i++){
                souvenirs[i] = Long.parseLong(st.nextToken());
            }
            long left = 0;
            long right = souvenirs.length;
            long mid = 0;
            long tempAmount = 0;
            long[] tempSouvenirs = new long[souvenirs.length];
            long sum = 0;
            long numSouvenirs = 0;
            while(left <= right){
                mid = (left + right)/2;
                for(int i = 0; i < souvenirs.length; i++){
                    tempSouvenirs[i] = souvenirs[i] + (mid * (i + 1));
                }
                Arrays.sort(tempSouvenirs);
                tempAmount = budget;
    //            System.out.println(mid + " " + Arrays.toString(tempSouvenirs));
    //            System.out.println(left + " " + mid + " " + right);
                for(int i = 0; i < mid; i++){
                    tempAmount -= tempSouvenirs[i];
                }
                if(tempAmount < 0){
                    right = mid - 1;
                } else{
                    left = mid + 1;
                    numSouvenirs = mid;
                    sum = budget - tempAmount;
                }
            }
            pw.println(numSouvenirs + " " + sum);
            pw.close();
        }
    }