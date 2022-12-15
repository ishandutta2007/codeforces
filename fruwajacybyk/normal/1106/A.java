import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main {
	
    public static void main(String[] args) {
    		Scanner input = new Scanner(System.in);
				int n = input.nextInt(); input.nextLine(); 
				String[] board = new String[500];
				for (int i = 0; i < n; i++) {
					board[i] = input.nextLine();
				}
				int[] dx = {-1, 1};
				int answer = 0;
				for (int i = 1; i < n-1; i++) {
					for (int j = 1; j < n - 1; j++) {
						if (board[i].charAt(j) != 'X') continue;
						int ile = 0;
						for (int u = 0; u < 2; u++) {
							for (int w = 0; w < 2; w++) {
								if (board[i+dx[u]].charAt(j+dx[w])  == 'X') ile++;
							}
						}
						if (ile == 4) answer++;
					}
				}
				System.out.println(answer);

		}
}