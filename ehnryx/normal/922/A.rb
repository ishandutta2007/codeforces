x, y = gets().split().map(&:to_i)
if y == 0; puts "No";
elsif y == 1; puts (x == 0) ? "Yes" : "No";
else; x -= y-1; puts (x % 2 == 0 and x >= 0) ? "Yes" : "No";
end